#include <iostream>
#include "propagate.h"

const int ID_BUTTON = 1;

Propagate::Propagate(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(250, 130))
{
  MyPanel *panel = new MyPanel(this, -1);

  new MyButton1(panel, ID_BUTTON, wxT("Ok"));

  Connect(ID_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(Propagate::OnClick));

  Centre();
}


void Propagate::OnClick(wxCommandEvent& event) 
{
  std::cout << "event reached frame class" << std::endl;
  event.Skip();
}


MyPanel::MyPanel(wxFrame *frame, int id)
    : wxPanel(frame, id)
{
  Connect(ID_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(MyPanel::OnClick));
} 

void MyPanel::OnClick(wxCommandEvent& event) 
{
  std::cout << "event reached panel class" << std::endl;
  event.Skip();
}


MyButton1::MyButton1(MyPanel *mypanel, int id, const wxString& label)
    : wxButton(mypanel, id, label, wxPoint(15, 15))
{
  Connect(ID_BUTTON, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler(MyButton1::OnClick));
} 


void MyButton1::OnClick(wxCommandEvent& event) 
{
  std::cout << "event reached button class" << std::endl;
  event.Skip();
}