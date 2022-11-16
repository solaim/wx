#include "toolbars.h"

Toolbar::Toolbar(const wxString& title)

      : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{

    wxImage::AddHandler( new wxPNGHandler );
    wxBitmap exit(wxImage(wxT("exit.png")), wxBITMAP_TYPE_PNG);
    wxBitmap newb(wxImage(wxT("new.png")), wxBITMAP_TYPE_PNG);
    wxBitmap open(wxImage(wxT("open.png")), wxBITMAP_TYPE_PNG);
    wxBitmap save(wxImage(wxT("save.png")), wxBITMAP_TYPE_PNG);

    wxBoxSizer *vbox = new wxBoxSizer(wxVERTICAL);
    toolbar1 = new wxToolBar(this, wxID_ANY);
    toolbar1->AddTool(wxID_ANY, wxT("new"), newb, wxT(""));
    toolbar1->AddTool(wxID_ANY, wxT("open"), open, wxT(""));
    toolbar1->AddTool(wxID_ANY, wxT("save"), save, wxT(""));
    toolbar1->Realize();
    toolbar2 = new wxToolBar(this, wxID_ANY);
    toolbar2->AddTool(wxID_CLOSE, wxT("exit"), exit, wxT("Exit application"));
    toolbar2->Realize();
    vbox->Add(toolbar1, 0, wxEXPAND);
    vbox->Add(toolbar2, 0, wxEXPAND);
    SetSizer(vbox);
    Connect(wxID_CLOSE, wxEVT_COMMAND_TOOL_CLICKED, 
        wxCommandEventHandler(Toolbar::OnQuit));
    
    Centre();
}

void Toolbar::OnQuit(wxCommandEvent& WXUNUSED(event)) {

    Close(true);
}

