//
// Created by Alexander Sherstnev on 5/19/18.
//

#include "wx/wxBaseApplication.h"
#include "wx/wxRenderContext.h"
#include "wxRenderFrame.h"

bool wxBaseApplication::OnInit()
{
    _renderFrame = new wxRenderFrame(this, _title, _position, _size);

    bool result = OnInitialize();
    if (result)
    {
        _renderFrame->Show(true);
        ActivateMainLoop(true);
    }

    return result;
}

int wxBaseApplication::OnExit()
{
    return OnDeinitialize();
}

void wxBaseApplication::SetTitle(const String& title)
{
    _title = title;
    if (_renderFrame != nullptr)
    {
        _renderFrame->SetTitle(_title);
    }
}

void wxBaseApplication::SetPosition(const Point& position)
{
    _position = position;
    if (_renderFrame != nullptr)
    {
        _renderFrame->SetPosition(_position);
    }
}

void wxBaseApplication::SetSize(const Size& size)
{
    _size = size;
    if (_renderFrame != nullptr)
    {
        _renderFrame->SetSize(_size);
    }
}

void wxBaseApplication::ActivateMainLoop(bool activate)
{
    if (activate && !_isMainLoopActive)
    {
        Connect(wxID_ANY, wxEVT_IDLE, wxIdleEventHandler(wxBaseApplication::OnIdleHandle));
        _isMainLoopActive = true;
    }
    else if (!activate && _isMainLoopActive)
    {
        Disconnect(wxEVT_IDLE, wxIdleEventHandler(wxBaseApplication::OnIdleHandle));
        _isMainLoopActive = false;
    }
}

void wxBaseApplication::Tick(wxDC& dc)
{
    wxRenderContext context(dc);
    OnTick(context);
}

void wxBaseApplication::Resize(const Size& size)
{
    OnSize(size);
}

void wxBaseApplication::OnIdleHandle(wxIdleEvent& evt)
{
    if (_isMainLoopActive)
    {
        if (_renderFrame != nullptr)
        {
            _renderFrame->TickNow();
        }

        evt.RequestMore();
    }
}