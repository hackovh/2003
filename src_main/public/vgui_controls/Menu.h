//========= Copyright � 1996-2003, Valve LLC, All rights reserved. ============
//
// The copyright to the contents herein is the property of Valve, L.L.C.
// The contents may be used and/or copied only with the written permission of
// Valve, L.L.C., or in accordance with the terms and conditions stipulated in
// the agreement/contract under which the contents have been supplied.
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================

#ifndef MENU_H
#define MENU_H

#ifdef _WIN32
#pragma once
#endif

#include <vgui_controls/Panel.h>
#include <UtlLinkedList.h>
#include <UtlVector.h>

namespace vgui
{

class MenuItem;
class ScrollBar;
enum MouseCode;

//-----------------------------------------------------------------------------
// Purpose: A menu is a list of items that can be selected with one click, navigated
//			with arrow keys and/or hot keys, and have a lit behavior when mouse over.
//			It is NOT the button which opens the menu, but only the menu itself.
//
// Behaviour spec:
// Menu navigation can be done in 2 modes, via keyboard keys and via mouse.
// Clicking on menu button opens menu.
// Only one item in a menu is highlighted at a time.
// Only one submenu in a menu is open at a time.
// Disabled menuitems get highlighted via mouse and keys but will not activate.
//
// Mouse:
//   Moving mouse into a menuitem highlights it.
//   If the menuitem has a cascading menu, the menu opens when the mouse enters
//    the menuitem. The cascading menuitem stays highlighted while its menu is open.
//   No submenu items are highlighted by default.
//   Moving the mouse into another menuitem closes any previously open submenus in the list.
//   Clicking once in the menu item activates the menu item and closes all menus.
//   Moving the mouse off a menuitem unhighlights it.
//   The scroll bar arrows can be used to move up/down the menu one item at a time.
//   The clicking and dragging on the scroll bar nob also scrolls the menu items.
//   If a highlighed menuitem scrolls off, and the user then begins navigating via keys,
//    the menu will snap the scroll bar so the highlighted item is visible.
//   If user has been navigating via keys, moving the mouse over a menu item 
//    highlights it.
// Mousewheel:
//   You must have the mouse inside the menu/scroll bar to use the wheel.
//   The mouse wheel moves the highlighted menuitem up or down the list.
//   If the list has no scroll bar the wheel will cycle from the bottom of the list
//    to the top of the list and vice versa.
//   If the list has a scrollbar the mouse wheel will stop at the top or bottom
//    of the list. 
//   If the mouse is over the scroll bar no items are highlighted.
// Keyboard:
//   When a menu is opened, no items are highlighted.
//   If a menuitem has a cascading menu it does not open when the item is highlighted.
//   The down arrow selects the next item in the list. 
//    (first item if none are highlighted and there is a scrollbar).
//   The up arrow selects the previous item in the list 
//    (first item if none are highlighted and there is a scrollbar, last item if none are
//    highlighted and there is no scrollbar).
//   Selecting a new menuitem closes any previously open submenus in the list.
//   The enter key activates the selected item and closes all menus.
//   If the selected item has a cascading menu, activating it opens its submenu.
//   These may also be activated by pressing the right arrow.
//   Pressing the left arrow closes the submenu.
//   When the submenu is opened the cascading menuitem stays highlighted.
//   No items in the submenu are highlighted when it is opened.
//   
//   Note: Cascading menuitems in menus with a scrollbar is not supported.
//         Its a clunky UI and if we want this we should design a better solution,
//         perhaps along the lines of how explorer's bookmarks does it.
//         It currently functions, but there are some arm/disarm bugs.
//
//
//-----------------------------------------------------------------------------
class Menu : public Panel
{
	friend MenuItem;
public:
	Menu(Panel *parent, const char *panelName);
	~Menu();

	// Add a simple text item to the menu
	virtual int AddMenuItem( const char *itemName, const char *itemText, const char *command, Panel *target, KeyValues *userData = NULL );
	virtual int AddMenuItem( const char *itemName, const wchar_t *wszItemText, const char *command, Panel *target, KeyValues *userData = NULL );

	virtual int AddMenuItem( const char *itemName, const char *itemText, KeyValues *message, Panel *target , KeyValues *userData = NULL);
	virtual int AddMenuItem( const char *itemName, const wchar_t *wszItemText, KeyValues *message, Panel *target , KeyValues *userData = NULL);
	
	virtual int AddMenuItem( const char *itemText, const char *command, Panel *target , KeyValues *userData = NULL);
	virtual int AddMenuItem( const char *itemText, KeyValues *message, Panel *target, KeyValues *userData = NULL );
	virtual int AddMenuItem( const char *itemText, Panel *target, KeyValues *userData = NULL );

	// Add a checkable item to the menu
	virtual int AddCheckableMenuItem( const char *itemName, const char *itemText, const char *command, Panel *target, KeyValues *userData = NULL );
	virtual int AddCheckableMenuItem( const char *itemName, const wchar_t *wszItemText, const char *command, Panel *target, KeyValues *userData = NULL );

	virtual int AddCheckableMenuItem( const char *itemName, const char *itemText, KeyValues *message, Panel *target, KeyValues *userData = NULL );
	virtual int AddCheckableMenuItem( const char *itemName, const wchar_t *wszItemText, KeyValues *message, Panel *target, KeyValues *userData = NULL );

	virtual int AddCheckableMenuItem( const char *itemText, const char *command, Panel *target , KeyValues *userData = NULL);
	virtual int AddCheckableMenuItem( const char *itemText, KeyValues *message, Panel *target, KeyValues *userData = NULL );
	virtual int AddCheckableMenuItem( const char *itemText, Panel *target, KeyValues *userData = NULL );

	// Add a cascading menu item to the menu
	virtual int AddCascadingMenuItem( const char *itemName, const char *itemText, const char *command, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );
	virtual int AddCascadingMenuItem( const char *itemName, const wchar_t *wszItemText, const char *command, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );

	virtual int AddCascadingMenuItem( const char *itemName, const char *itemText, KeyValues *message, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );
	virtual int AddCascadingMenuItem( const char *itemName, const wchar_t *wszItemText, KeyValues *message, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );
	
	virtual int AddCascadingMenuItem( const char *itemText, const char *command, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );
	virtual int AddCascadingMenuItem( const char *itemText, KeyValues *message, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );
	virtual int AddCascadingMenuItem( const char *itemText, Panel *target, Menu *cascadeMenu, KeyValues *userData = NULL );

	// Add a custom panel to the menu
	virtual int AddMenuItem( MenuItem *panel );

	// Sets the values of a menu item at the specified index
	virtual void UpdateMenuItem(int itemID, const char *itemText,KeyValues *message, KeyValues *userData = NULL);
	virtual void UpdateMenuItem(int itemID, const wchar_t *wszItemText,KeyValues *message, KeyValues *userData = NULL);

	virtual bool IsValidMenuID(int itemID);
	virtual int GetInvalidMenuID();

	virtual KeyValues *GetItemUserData(int itemID);

	virtual void SetItemEnabled(const char *itemName, bool state);
	virtual void SetItemEnabled(int itemID, bool state);

	// Clear the menu, deleting all the menu items within
	virtual void DeleteAllItems();

	// Override the auto-width setting with a single fixed width
	virtual void SetFixedWidth( int width );

	// sets the height of each menu item
	virtual void SetMenuItemHeight(int itemHeight);

	// Set the max number of items visible (scrollbar appears with more)
	virtual void SetNumberOfVisibleItems( int numItems );

	// Set up the menu items layout
	virtual void PerformLayout( void );

	virtual void SetBorder(class IBorder *border);
	virtual void ApplySchemeSettings(IScheme *pScheme);

	// Hotkey handling
	virtual void OnKeyTyped(wchar_t unichar);
	// Menu nagivation etc.
	virtual void OnKeyCodeTyped(enum KeyCode code);

	// Visibility
	virtual void SetVisible(bool state);

	// Activates item in the menu list, as if that menu item had been selected by the user
	virtual void ActivateItem(int itemID);
	virtual void ActivateItemByRow(int row);
	virtual int GetActiveItem();

	// Return the number of items currently in the menu list
	virtual int GetItemCount();

	// return the menuID of the n'th item in the menu list, valid from [0, GetNumberOfMenuItems)
	virtual int GetMenuID(int index);
	
	// Return the number of items currently visible in the menu list
	int GetCurrentlyVisibleItemsCount();
	
	MenuItem *GetMenuItem(int itemID);
	void CloseOtherMenus(MenuItem *item);
	virtual void OnKillFocus();

	int GetMenuMode();
	enum MenuMode
	{
		MOUSE = 0,
		KEYBOARD,
	};

	void SetCurrentlyHighlightedItem(int itemID);
	int GetCurrentlyHighlightedItem();
	void ClearCurrentlyHighlightedItem();
	
	// Set the checked state of a checkable menuItem
	void SetMenuItemChecked(int itemID, bool state);
	bool IsChecked(int index); // check if item is checked.

	
	void SetMinimumWidth(int width);
	int  GetMinimumWidth();

	// baseclass overrides to chain colors through to cascade menus
	virtual void SetFgColor( Color newColor );
	virtual void SetBgColor( Color newColor );

protected:
	// helper functions	
	int AddMenuItemCharCommand(MenuItem *item, const char *command, Panel *target, KeyValues *userData);
	int AddMenuItemKeyValuesCommand(MenuItem *item, KeyValues *message, Panel *target, KeyValues *userData);

	// vgui result reporting
	virtual void OnCommand( const char *command );
	virtual void OnMenuItemSelected(Panel *panel);
	virtual void AddScrollBar();
	virtual void RemoveScrollBar();
	virtual void OnSliderMoved();
	virtual void Paint();
	virtual void LayoutMenuBorder();
	virtual void MakeItemsVisibleInScrollRange();
	virtual void OnMouseWheeled(int delta);


	void CalculateWidth();
	void ForceCalculateWidth();

	void LayoutScrollBar();
	void PositionCascadingMenu();
	void SizeMenuItems();
	void OnCursorMoved(int x, int y);
	void OnKeyCodePressed(KeyCode code);
	void OnMenuClose();
	void OnKeyModeSet();

	void SetCurrentlySelectedItem(MenuItem *item);
	void SetCurrentlySelectedItem(int itemID);
	void OnCursorEnteredMenuItem(VPANEL menuItem);
	void OnCursorExitedMenuItem(VPANEL menuItem);

	void MoveAlongMenuItemList(int direction, int loopCount); 

	enum 
	{
		SCROLLBAR_SIZE = 18,  // the width of a scrollbar
		DEFAULT_MENU_ITEM_HEIGHT = 22, // height of items in the menu
		UP = -1, // used for moving up/down list of menu items in the menu
		DOWN = 1
	};

	DECLARE_PANELMAP();

private:

	int 			m_iMenuItemHeight;
	int 			m_iFixedWidth;
	int 			m_iMinimumWidth; // a minimum width the menu has to be if it is not fixed width
	int 			m_iNumVisibleLines;	// number of items in menu before scroll bar adds on
//	Dar<MenuItem *> m_MenuItems;
	ScrollBar 		*m_pScroller;

	CUtlLinkedList<MenuItem*, int> 	m_MenuItems;
	CUtlVector<int>					m_SortedItems;		// used for visual 

	bool 			_sizedForScrollBar;  // whether menu has been sized for a scrollbar
	int 			_menuWide;
	bool 			_recalculateWidth;
	int 			m_iCurrentlySelectedItemID;
	int 			m_iInputMode;
	int 			m_iCheckImageWidth; // the size of the check box spot on a checkable menu.
	int 			m_iProportionalScrollBarSize;

	Color 			_borderDark;
	int 			m_iActivatedItem;

	typedef Panel BaseClass;
};

} // namespace vgui

#endif // MENU_H
