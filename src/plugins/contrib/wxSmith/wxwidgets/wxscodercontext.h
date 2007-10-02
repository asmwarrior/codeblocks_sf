/*
* This file is part of wxSmith plugin for Code::Blocks Studio
* Copyright (C) 2007  Bartlomiej Swiecki
*
* wxSmith is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* wxSmith is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with wxSmith; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA
*
* $Revision$
* $Id$
* $HeadURL$
*/

#ifndef WXSCODERCONTEXT_H
#define WXSCODERCONTEXT_H

#include <wx/string.h>
#include <wx/arrstr.h>
#include <wx/hashmap.h>
#include <wx/hashset.h>
#include "../wxscodinglang.h"

/** \brief This struct is responsible for keeping current code context while generating resource
 *
 * This struct keeps informations needed to properly generate and store source code.
 * It contains code built so far, lists of include files, declarations etc.
 * It may also contain other data stored between generation of code in different items
 * in form of wxString->wxString map.
 */
struct wxsCoderContext
{
    WX_DECLARE_STRING_HASH_MAP(wxString,ExtraMap);
    WX_DECLARE_HASH_SET(wxString,wxStringHash,wxStringEqual,wxStringSet);

    wxsCodingLang m_Language;               ///< \brief Language in which code should be generated
    long          m_Flags;                  ///< \brief Flags used to generate code
    wxString      m_WindowParent;           ///< \brief Parent window name

    wxStringSet m_LocalHeaders;             ///< \brief List of headers included inside .cpp file which are included inside pch file
    wxStringSet m_LocalHeadersNonPCH;       ///< \brief List of headers included inside .cpp file which are not included in pch file
    wxStringSet m_GlobalHeaders;            ///< \brief List of headers contining declarations of resource's items included inside pch file
    wxStringSet m_GlobalHeadersNonPCH;      ///< \brief List of headers contining declarations of resource's items not included inside pch file
    wxStringSet m_ForwardDeclarations;      ///< \brief List of forward declarations of resource's items
    wxStringSet m_ForwardDeclarationsNonPCH;///< \brief List of forward declarations of resource's items
    wxStringSet m_LocalDeclarations;        ///< \brief List of declarations of local items (not visible in resource's class)
    wxStringSet m_GlobalDeclarations;       ///< \brief List of declarations of global items (which are being members of resorce's class)
    wxArrayString m_IdEnumerations;         ///< \brief Code used to create list of identifiers as members of resource clas
    wxArrayString m_IdInitializions;        ///< \brief Code used to initialize list of identifiers
    wxString    m_XRCFetchingCode;          ///< \brief Code which will fetch items from XRC file after it's loaded (through querying with IDs)
    wxString    m_BuildingCode;             ///< \brief Code which builds resource's items manually (when not using XRC file)
    wxString    m_EventsConnectingCode;     ///< \brief Code used to connect events

    ExtraMap      m_Extra;                  ///< \brief Extra data used to exchange informations between items while they generate code

    /** \brief Adding header file into current context */
    void AddHeader(const wxString& Header,const wxString& DeclaredClass,long HeaderFlags=0);

    /*** \brief Adding forward declaration of item's class */
    void AddDeclaration(const wxString& Declaration);

    /** \brief Adding XRC fetching code */
    void AddXRCFetchingCode(const wxString& Code);

    /** \brief Adding Manually building code */
    void AddBuildingCode(const wxString& Code);

    /** \brief Adding event connecting code */
    void AddEventCode(const wxString& Code);

    /** \brief Adding id-generating code */
    void AddIdCode(const wxString& Enumeration,const wxString& Initialization);
};

#endif
