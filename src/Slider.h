#include <wx/wx.h>
#include <wx/slider.h>

class MyPanel1 : public wxPanel
{
public:
    MyPanel1(wxFrame *parent);

    void OnPaint(wxPaintEvent& event);
    void OnScroll(wxScrollEvent& event);

    wxSlider *slider;
    int fill;

};

class Slider : public wxFrame
{
public:
    Slider(const wxString& title);

    MyPanel1 *panel;

};

const int ID_SLIDER1 = 100;