#include "toolbar.h"

Toolbar::Toolbar(const wxString& title)
      : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(280, 180))
{

    wxBitmap exit(wxImage(wxT("exit.png")));
    wxToolBar *toolbar = CreateToolBar();
    toolbar->AddTool(wxID_CLOSE, wxT("exit"), exit, wxT("Exit application"));
    toolbar->Realize();
    Connect(wxID_CLOSE, wxEVT_COMMAND_TOOL_CLICKED, 
        wxCommandEventHandler(Toolbar::OnQuit));
    
    Centre();
}

void Toolbar::OnQuit(wxCommandEvent& WXUNUSED(event)) {

    Close(true);
}