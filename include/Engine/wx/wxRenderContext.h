//
// Created by Alexander Sherstnev on 5/19/18.
//

#pragma once

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "Render/RenderContext.h"

/**
 * wxWidgets render context.
 */
class wxRenderContext : public RenderContext
{
public:
    /**
     * Default constructor.
     * @param dc - wxWidget device context.
     */
    wxRenderContext(wxDC& dc);

    // Begin RenderContext Interface
    void Clear() override;
    void SetBackgroundColor(const Color& color) override;
    void SetOutlineColor(const Color& color) override;
    void SetFillColor(const Color& color) override;
    void DrawPoint(const Point& point) override;
    void DrawPolygon(const Point points[], int size) override;
    // End RenderContext Interface

private:
    /** Reference to device context. */
    wxDC& _dc;
};
