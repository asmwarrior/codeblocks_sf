#include "../wxsheaders.h"
#include "wxslistctrl.h"

#include <wx/listbox.h>

WXS_ST_BEGIN(wxsListCtrlStyles)
    WXS_ST_CATEGORY("wxListCtrl")
    WXS_ST(wxLC_LIST)
    WXS_ST(wxLC_REPORT)
    WXS_ST(wxLC_VIRTUAL)
    WXS_ST(wxLC_ICON)
    WXS_ST(wxLC_SMALL_ICON)
    WXS_ST_MASK(wxLC_ALIGN_TOP,wxsSFWin,0,true)
    WXS_ST(wxLC_ALIGN_LEFT)
    WXS_ST_MASK(wxLC_AUTOARRANGE,wxsSFWin,0,true)
    WXS_ST(wxLC_EDIT_LABELS)
    WXS_ST(wxLC_NO_HEADER)
    WXS_ST(wxLC_SINGLE_SEL)
    WXS_ST(wxLC_SORT_ASCENDING)
    WXS_ST(wxLC_SORT_DESCENDING)
    WXS_ST(wxLC_HRULES)
    WXS_ST(wxLC_VRULES)
WXS_ST_END(wxsListCtrlStyles)

WXS_EV_BEGIN(wxsListCtrlEvents)
    WXS_EVI(EVT_LIST_BEGIN_DRAG,wxListEvent,BeginDrag)
    WXS_EVI(EVT_LIST_BEGIN_RDRAG,wxListEvent,BeginRDrag)
    WXS_EVI(EVT_LIST_BEGIN_LABEL_EDIT,wxListEvent,BeginLabelEdit)
    WXS_EVI(EVT_LIST_END_LABEL_EDIT,wxListEvent,EndLabelEdit)
    WXS_EVI(EVT_LIST_DELETE_ITEM,wxListEvent,DeleteItem)
    WXS_EVI(EVT_LIST_DELETE_ALL_ITEMS,wxListEvent,DeleteAllItems)
    WXS_EVI(EVT_LIST_ITEM_SELECTED,wxListEvent,ItemSelect)
    WXS_EVI(EVT_LIST_ITEM_DESELECTED,wxListEvent,ItemDeselect)
    WXS_EVI(EVT_LIST_ITEM_ACTIVATED,wxListEvent,ItemActivated)
    WXS_EVI(EVT_LIST_ITEM_FOCUSED,wxListEvent,ItemFocused)
    WXS_EVI(EVT_LIST_ITEM_MIDDLE_CLICK,wxListEvent,ItemMClick)
    WXS_EVI(EVT_LIST_ITEM_RIGHT_CLICK,wxListEvent,ItemRClick)
    WXS_EVI(EVT_LIST_KEY_DOWN,wxListEvent,KeyDown)
    WXS_EVI(EVT_LIST_INSERT_ITEM,wxListEvent,InsertItem)
    WXS_EVI(EVT_LIST_COL_CLICK,wxListEvent,ColumnClick)
    WXS_EVI(EVT_LIST_COL_RIGHT_CLICK,wxListEvent,ColumnRClick)
    WXS_EVI(EVT_LIST_COL_BEGIN_DRAG,wxListEvent,ColumnBeginDrag)
    WXS_EVI(EVT_LIST_COL_DRAGGING,wxListEvent,ColumnDragging)
    WXS_EVI(EVT_LIST_COL_END_DRAG,wxListEvent,ColumnEndDrag)
    WXS_EVI(EVT_LIST_CACHE_HINT,wxListEvent,CacheHint)
    WXS_EV_DEFAULTS()
WXS_EV_END(wxsListCtrlEvents)

wxsDWDefineBegin(wxsListCtrl,wxListCtrl,
        WXS_THIS = new wxListCtrl(WXS_PARENT,WXS_ID,WXS_POS,WXS_SIZE,WXS_STYLE);
    )
wxsDWDefineEnd()
