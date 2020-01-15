//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "wxRenderFrame.h"
#include "wxRenderPanel.h"
#include "wx/wxBaseApplication.h"

wxRenderFrame::wxRenderFrame(wxBaseApplication* application, const String& title, const Point& position, const Size& size)
    : wxFrame(nullptr, wxID_ANY, title, position, size), _application(application)
{
    _renderPanel = new wxRenderPanel(this);

    wxBoxSizer* sizer = new wxBoxSizer(wxHORIZONTAL);
    sizer->Add(_renderPanel, 1, wxEXPAND);

    SetSizer(sizer);
    SetAutoLayout(true);
}

void wxRenderFrame::TickNow()
{
    if (_renderPanel != nullptr)
    {
        _renderPanel->TickNow();
    }
}

void wxRenderFrame::Tick(wxDC& dc)
{
    if (_application != nullptr)
    {
        _application->Tick(dc);
    }
}

void wxRenderFrame::OnClose(wxCloseEvent& evt)
{
    if (_application != nullptr)
    {
        _application->ActivateMainLoop(false);
    }

    evt.Skip();
}

void wxRenderFrame::OnSize(wxSizeEvent& evt)
{
    Size size = evt.GetSize();
    SetSize(size);
    if (_application != nullptr)
    {
        _application->Resize(size);
    }

    evt.Skip();
}

BEGIN_EVENT_TABLE(wxRenderFrame, wxFrame)
    EVT_CLOSE(wxRenderFrame::OnClose)
    EVT_SIZE(wxRenderFrame::OnSize)
END_EVENT_TABLE()