//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Core.h"
#include "BaseApplication.h"

/** Forward declarations. */
class wxRenderFrame;

/**
 * Base application which using wxWidgets for general window creation, deletion etc.
 */
class wxBaseApplication : public wxApp, public BaseApplication
{
    friend class wxRenderFrame;

public:
    // Begin wxApp Interface
    bool OnInit() override;
    int OnExit() override;
    // End wxApp Interface

    // Begin BaseApplication Interface
    void SetTitle(const String& title) override;
    void SetPosition(const Point& position) override;
    void SetSize(const Size& size) override;
    // End BaseApplication Interface

private:
    /**
     * Activate main loop.
     * @param activate - True if need activate main loop.
     */
    void ActivateMainLoop(bool activate);

    /**
     * One application tick.
     * @param dc - wxWidgets device context.
     */
    void Tick(wxDC& dc);

    /**
     * Resize event handler.
     * @param size - New size
     */
    void Resize(const Size& size);

    /**
     * Idle event handler.
     * @param evt - Reference to event data.
     */
    void OnIdleHandle(wxIdleEvent& evt);

    /** Reference to the render frame. */
    wxRenderFrame* _renderFrame;

    /** True if main loop is active now. */
    bool _isMainLoopActive;

    /** Application title. */
    wxString _title;

    /** Application position. */
    wxPoint _position;

    /** Application size. */
    wxSize _size;
};

