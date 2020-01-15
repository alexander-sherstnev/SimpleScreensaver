//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Core.h"

/** Forward declarations. */
class wxBaseApplication;
class wxRenderPanel;

/**
 * Application render frame using for organization of layout.
 */
class wxRenderFrame : public wxFrame
{
    friend class wxBaseApplication;
    friend class wxRenderPanel;

public:
    /**
     * Default constructor.
     * @param application - Application.
     * @param title - Frame title.
     * @param position - Frame initial position.
     * @param size - Frame initial size.
     */
    wxRenderFrame(wxBaseApplication* application, const String& title, const Point& position, const Size& size);

private:
    /**
     * Called by the application when next tick.
     */
    void TickNow();

    /**
     * Tick one frame.
     * @param dc - Device context.
     */
    void Tick(wxDC& dc);

    /**
     * Close event handler.
     * @param evt - Close event data.
     */
    void OnClose(wxCloseEvent& evt);

    /**
     * Resize event handler
     * @param evt - Size event data.
     */
    void OnSize(wxSizeEvent& evt);

    /** Refenrece to the actual application. */
    wxBaseApplication* _application;

    /** Reference to the actual render panel. */
    wxRenderPanel* _renderPanel;

    /** Declare event table for this frame class. */
    DECLARE_EVENT_TABLE();
};
