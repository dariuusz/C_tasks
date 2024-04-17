/************************************************************************
*                                                                       *
*               DIGITAL APPLICATIONS INTERNATIONAL LIMITED              *
*                 MILAN COURT, BIRDHALL LANE, CHEADLE HEATH             *
*                          CHESHIRE SK3 0WZ                             *
*                           TEL. 0161-374-6000                          *
*                                                                       *
*                           DAI TEMPLATE MODULE                         *
*                                                                       *
*************************************************************************
*                                                                       *
* Module Name : web_stock_check_reason_lib.c                            *
*                                                                       *
* Edit Record (most recent edit at top of list)                         *
* Date          By      CF      Comments                                *
* ---------     ---     ----    --------------------------------------- *
* XX-Xxx-XX     AutoGen         Module Created                          *
*************************************************************************
*
* stock_check_reason processing library.
*
************************************************************************/


/*---------- External References ------------------------------------------*/


#define web_stock_check_reason_lib TRUE
#include <cd_declarations.h>
#include <web_headers.h>

/*---------- Global Declarations ------------------------------------------*/


#ifndef web_stock_check_reason_lib_INCLUDED /* START OF GLOBAL DECLARATIONS - key line do not alter */


#endif/* END OF GLOBAL DECLARATIONS - Edit keyline, do not alter */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_StdListSetup
**
**DESCRIPTION
**   Called before the std list screen is drawn, use to set default list length,
**   default sort or draw something to the screen above the list
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_StdListSetup( void )
{

}/* WEB_STOCK_CHECK_REASON_StdListSetup */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_StdDetailSetup
**
**DESCRIPTION
**   Called before the std detail screen is drawn
**   use to draw something to the screen above the detail section
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_StdDetailSetup(
  REC_NO          RecNo,
  char            *TabStr )
{

}/* WEB_STOCK_CHECK_REASON_StdDetailSetup */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_DetailListSectionSetup
**
**DESCRIPTION
**   Called before the std list section at the bottom of a detail screen is
**   drawn.  Use to set default list length, default sort or draw something
**   to the screen above the list
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_DetailListSectionSetup(
  REC_NO          RecNo,
  char            *TabStr )
{

}/* WEB_STOCK_CHECK_REASON_DetailListSectionSetup */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_DetailListSectionDrawFunc
**
**DESCRIPTION
**   Draws the section at the bottom of a detail screen.
**   returning TRUE will tell the calling function that this section has been
**   drawn and the HTML rendered here will be the only thing shown on this
**   section of the screen
**
*/
GLOBAL BOOLEAN WEB_STOCK_CHECK_REASON_DetailListSectionDrawFunc(
  REC_NO          RecNo,
  char            *TabStr )
{
  return FALSE; /* amend to return TRUE if this is really drawing the section */

}/* WEB_STOCK_CHECK_REASON_DetailListSectionDrawFunc */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_DetailDetailSectionDrawFunc
**
**DESCRIPTION
**   Draws the section at the top of a detail screen.
**   returning TRUE will tell the calling function that this section has been
**   drawn and the HTML rendered here will be the only thing shown on this
**   section of the screen
**
*/
GLOBAL BOOLEAN WEB_STOCK_CHECK_REASON_DetailDetailSectionDrawFunc(
  REC_NO          RecNo,
  char            *TabStr )
{
  return FALSE; /* amend to return TRUE if this is really drawing the section */

}/* WEB_STOCK_CHECK_REASON_DetailDetailSectionDrawFunc */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_AddDetailActions
**
**DESCRIPTION
**   Adds any actions to the 'Actions' menu on the detail screen.
**   These should be handled in STOCK_CHECK_REASON_HandleDetailScreenInputs.
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_AddDetailActions(
  REC_NO          RecNo SUPPRESS_UNUSED_WARNING,
  char            *TabStr )
{

  if( USER_PrivilegOn( USER_CurrentUserRecNo, FUNCTION_STOCK_CHECK_REASON ))
  {
    HTML_DrawActionConfirm( "Delete Stock Check Reason",
                            "Delete Stock Check Reason?",
                            "Delete",
                            "Cancel",
                            WEB_UrlMyUrlWithParams( 1, "delete_stock_check_reason", "Y" )

    );
  }

}/* WEB_STOCK_CHECK_REASON_AddDetailActions */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_DrawDetailButtons
**
**DESCRIPTION
**   Draws any buttons to be shown on the detail screen
**   These should be handled in STOCK_CHECK_REASON_HandleDetailScreenInputs.
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_DrawDetailButtons(
  REC_NO          RecNo,
  char            *TabStr )
{

}/* WEB_STOCK_CHECK_REASON_DrawDetailButtons */

// GLOBAL char *WEB_STOCK_CHECK_REASON_CHECK_METHOD_Dropdown( void )
// {
//   static HTML_LINE_TYPE       DropdownStr = { 0 };
//   int                         Len         =   0;

//   HTML_AddEnumToDropdown( DropdownStr,
//                           HTML_LINE_LEN,
//                           &Len,
//                           CHECK_METHOD_STOCK,
//                           CHECK_METHOD_DAMAGED,
//                           ( ENUM_FUNC ) ENUM_CheckMethodType
//                           );
// }

GLOBAL char *WEB_STK_CHECK_REQ_Dropdown( void )
{
  static HTML_LINE_TYPE         DropdownStr = {0};
  int                           Len = 0;


  HTML_AddEnumToDropdown( DropdownStr,
                        HTML_LINE_LEN,
                        &Len,
                        STK_CHECK_REQ_MANUAL,
                        STK_CHECK_REQ_INLINE,
                        (ENUM_FUNC) ENUM_StkCheckReqType );

  return DropdownStr;


} /* WEB_STOCK_CHECK_TYPE_Dropdown*/

/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_AddListActions
**
**DESCRIPTION
**   Adds any actions to the 'Actions' menu on the list screen.
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_AddListActions( void )
{

  if( USER_PrivilegOn ( USER_CurrentUserRecNo, FUNCTION_STOCK_CHECK_REASON ))
  {
    HTML_DrawActionPopupOverlay( "Add New Stock Check Reason",
                                 "Add New Stock Check Reason",
                                 "Confirm",
                                 "Cancel",
                                 4,

                                 "Reason Text",
                                 "delete_stock_cheack_reason_text",
                                 HTML_TEXT_FIELD,
                                 "",

                                 "Stock Check Type",
                                 "delete_stock_check_type",
                                 HTML_DROPDOWN_FIELD,
                                 WEB_STK_CHECK_REQ_TYPE_Dropdown(),

                                 "Check Method",
                                 "delete_stock_check_reason_method",
                                 HTML_DROPDOWN_FIELD,
                                 WEB_STOCK_CHECK_REASON_CHECK_METHOD_Dropdown(),

                                 "Block Putaway",
                                 "delete_stock_check_reason_block_putaway",
                                 HTML_DROPDOWN_FIELD,
                                 HTML_BooleanYesNoEnum()
                                );
  }
}/* WEB_STOCK_CHECK_REASON_AddListActions */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_DrawListButtons
**
**DESCRIPTION
**   Draws any buttons to be shown on the list screen
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_DrawListButtons( void )
{

}/* WEB_STOCK_CHECK_REASON_DrawListButtons */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_HandleDetailScreenInputs
**
**DESCRIPTION
**   Handle all inputs on the detail screen (resulting from action selections /
**   button presses. Use WEB_UrlGetXXXParam as appropriate
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_HandleDetailScreenInputs( REC_NO       RecNo )
{
    WEB_PARAM_TYPE ParamStr;

#define FAIL( ... )                 \
  { HTML_ErrorMessage( __VA_ARGS__ ); \
    return; }

  if( WEB_UrlGetStrParam( "delete_stock_check_reason", ParamStr, TRUE ) &&
        USER_PrivilegeOn( USER_CurrentUserRecNo, FUNCTION_STOCK_CHECK_REASON ) )
  {

    if( !STOCK_CHECK_REASON_Delete( RecNo, FALSE ) )
      FAIL( "Failed to delete: [%s]", STOCK_CHECK_REASON_ErrorString );
  }
}/* WEB_STOCK_CHECK_REASON_HandleDetailScreenInputs */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_HandleListActions
**
**DESCRIPTION
**   Use WEB_DF_ExecuteListActionFull or WEB_DF_ExecuteListActionWithBlockUpdate
**   for list actions to process actions before the list is re-drawn
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_HandleListActions( void )
{

}/* WEB_STOCK_CHECK_REASON_HandleListActions */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_RegisterAdditionalScreens
**
**DESCRIPTION
**   Function is called when initialising the web screens.
**   Use WEB_RegisterView to register a screen as available without adding to
**   the menus. Use WEB_RegisterMenuItem to register screen and add to the menus
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_RegisterAdditionalScreens( void )
{

}/* WEB_STOCK_CHECK_REASON_RegisterAdditionalScreens */


/*md01*************************************************************************
**
**NAME = WEB_STOCK_CHECK_REASON_OverrideFieldSettings
**
**DESCRIPTION
**   Function is called when initialising the web fields.
**   Use e.g. DF_OverrideSetStringFunc to change the function called when
**   changing a field
**
*/
GLOBAL void WEB_STOCK_CHECK_REASON_OverrideFieldSettings( void )
{

}/* WEB_STOCK_CHECK_REASON_OverrideFieldSettings */
