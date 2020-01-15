//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "wxRenderPanel.h"
#include "wxRenderFrame.h"

wxRenderPanel::wxRenderPanel(wxRenderFrame* parent)
    : wxPanel(parent),
      _renderFrame(parent)
{
}

void wxRenderPanel::TickNow()
{
    wxClientDC dc(this);
    Tick(dc);
}

void wxRenderPanel::TickEvent(wxPaintEvent& evt)
{
    wxPaintDC dc(this);
    Tick(dc);
}

void wxRenderPanel::Tick(wxDC& dc)
{
    if (_renderFrame != nullptr)
    {
        _renderFrame->Tick(dc);
    }
}

BEGIN_EVENT_TABLE(wxRenderPanel, wxPanel)
    EVT_PAINT(wxRenderPanel::TickEvent)
END_EVENT_TABLE()