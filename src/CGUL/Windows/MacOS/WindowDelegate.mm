// C++ General Utility Library (mailto:cgul@zethes.com)
// Copyright (C) 2012-2014, Joshua Brookover and Amber Thrall
// All rights reserved.

/** @file WindowDelegate.mm
 */

#ifndef DOXYGEN

#import "WindowDelegate.hpp"
#import "Application.hpp"
#include "../../Math/Vector4.hpp"
#include "../Window.hpp"

// leaving this here for future reference:
// http://stackoverflow.com/questions/4312338/how-to-use-the-object-property-of-nsnotificationcenter

@implementation WindowDelegate : NSObject

- (id) init: (CGUL::WindowStyle)style
{
    // Initialize the base application and make sure it's not nil
    if ((self = [super init]))
    {
        windowOpen = 1;

        // Define the size of the window
        NSRect frame = NSMakeRect(200, 200, style.size.x, style.size.y);

        // Define the style masks to be a titled window with close, max and min
        NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;

        // Adjust the window's sized based on the style mask
        //NSRect rect = [MacWindow contentRectForFrameRect: frame styleMask: styleMask];
        //NSRect rect = [MacWindow frameRectForContentRect: frame styleMask: styleMask];
        NSRect rect = frame;

        // Create the window based on the above specifications
        window = [[MacWindow alloc] initWithContentRect: rect styleMask: styleMask backing: NSBackingStoreBuffered defer: false];

        // Set the background color to black
        //[window setBackgroundColor: [NSColor colorWithCalibratedRed: style.backgroundColor.r / 255.0 green: style.backgroundColor.g / 255.0 blue: style.backgroundColor.b / 255.0 alpha: 1.0]];

        // Set the title of the window
        //NSString* str = [NSString stringWithCString:style.title.GetData().c_str() encoding:[NSString defaultCStringEncoding]];
        //[window setTitle:str];
        //[str release];

        // Make this object the delegate for the window
        [window setDelegate: self];

        // Create an OpenGL view for the window
        //view = [[OpenGLView alloc] init];

        // Get the default content of the window
        // defaultContent = [window contentView];

        // Set the content of the window to the OpenGL view we created
        //[window setContentView: view];

        view = nil;

        [window makeKeyAndOrderFront: self];

        lastMousePos = CGUL::SCoord32(0, 0);
    }

    return self;
}

- (void) windowWillClose: (NSNotification*) notification
{
    windowOpen = 0;
    /*if (window != nil)
    {
        // Uninitialize the application
        //app->uninitialize();

        // Release the window
        //[window release];
        //window = nil;

        // Terminate the application when the window closes
        //[NSApp terminate: self];
    }*/
}

- (void) windowDidResize: (NSNotification*) notification
{
    [view update];
}

- (void) dealloc
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    // Release the window and dealloc the super class
    //[window release
    if (windowOpen == 1)
    {
        [self close];
    }
    [super dealloc];
    [pool drain];
}

- (void) internalUpdate: (CGUL::Window*) cgulWindow
{
    // Get mouse position
    NSPoint mouseLoc;
    mouseLoc = [NSEvent mouseLocation]; //get current mouse position
    CGUL::SCoord32 mousePosition(mouseLoc.x, mouseLoc.y);
    mousePosition -= [self getPosition];
    CGUL::WindowMouseMoveEvent event;
    event.location = mousePosition;
    if (lastMousePos != mousePosition)
    {
        cgulWindow->onMouseMove.Trigger(event);
        lastMousePos = mousePosition;
    }
}

- (MacWindow*) Window
{
    return window;
}

- (int) isOpen
{
    return windowOpen;
}

- (void) setContent: (OpenGLView*) content
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [window setContentView: content];
    view = content;
    [pool drain];
}

- (void) close
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [window close];
    //[window release]; // TODO: don't we need to release the window? the segfault says otherwise
    [pool drain];
}

- (void) setTitle:(const CGUL::String&) title
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSString* str = [NSString stringWithCString:title.GetData().c_str() encoding:NSUTF8StringEncoding];
    [window setTitle:str];
    [pool drain];
}

- (CGUL::String) getTitle
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    CGUL::String ret([[window title] UTF8String]);
    [pool drain];
    return ret;
}

- (void) setBackgroundColor: (const CGUL::Color&) color
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    [window setBackgroundColor: [NSColor colorWithCalibratedRed: color.r / 255.0 green: color.g / 255.0 blue: color.b / 255.0 alpha: 1.0]];
    [pool drain];
}

- (CGUL::Color) getBackgroundColor
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSColor* color = [window backgroundColor];
    CGUL::Color ret([color redComponent] * 255, [color greenComponent] * 255, [color blueComponent] * 255, 255);
    [pool drain];
    return ret;
}

- (void) setWidth: (CGUL::UInt32) width
{
    NSRect frame = [window frame];
    frame.size.width = width;
    frame.size.height = [self getHeight];
    NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
    NSRect rect = [MacWindow frameRectForContentRect: frame styleMask: styleMask];
    [window setFrame: rect display: YES animate: NO];
}

- (CGUL::UInt32) getWidth
{
    NSRect rect = [[window contentView] frame];
    return rect.size.width;
}

- (void) setHeight: (CGUL::UInt32) height
{
    NSRect frame = [window frame];
    frame.size.width = [self getWidth];
    frame.size.height = height;
    NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
    NSRect rect = [MacWindow frameRectForContentRect: frame styleMask: styleMask];
    [window setFrame: rect display: YES animate: NO];
}

- (CGUL::UInt32) getHeight
{
    NSRect rect = [[window contentView] frame];
    return rect.size.height;
}

- (void) setSize: (const CGUL::UCoord32&) size
{
    NSRect frame = [window frame];
    frame.size.width = size.x;
    frame.size.height = size.y;
    NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;
    NSRect rect = [MacWindow frameRectForContentRect: frame styleMask: styleMask];
    [window setFrame: rect display: YES animate: NO];
}

- (CGUL::UCoord32) getSize
{
    NSRect rect = [[window contentView] frame];
    return CGUL::UCoord32(rect.size.width, rect.size.height);
}

- (void) setPosition: (const CGUL::SCoord32&) position
{
    // TODO
}

- (CGUL::SCoord32) getPosition
{
    // TODO
    return CGUL::SCoord32(100, 100);
}

- (void) setResizable: (CGUL::Boolean) resizable
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSUInteger styleMask = [window styleMask];
    if (resizable)
    {
        styleMask |= NSResizableWindowMask;
    }
    else
    {
        styleMask &= ~NSResizableWindowMask;
    }
    [window setStyleMask: styleMask];
    [pool drain];
}

- (CGUL::Boolean) getResizable
{
    NSAutoreleasePool* pool = [[NSAutoreleasePool alloc] init];
    NSUInteger styleMask = [window styleMask];
    [pool drain];
    return (styleMask & NSResizableWindowMask) > 0;
}

- (void) setAlwaysOnTop: (CGUL::Boolean) alwaysOnTop
{
    if (alwaysOnTop)
    {
        [window setLevel: NSFloatingWindowLevel];
    }
    else
    {
        [window setLevel: NSNormalWindowLevel];
    }
}

- (CGUL::Boolean) getAlwaysOnTop
{
    return ([window level] == NSFloatingWindowLevel);
}

- (CGUL::Vector4F) getFrameSize
{
    // Define the size of the window
    NSRect frame = NSMakeRect(0, 0, 0, 0);

    // Define the style masks to be a titled window with close, max and min
    NSUInteger styleMask = NSTitledWindowMask | NSClosableWindowMask | NSMiniaturizableWindowMask | NSResizableWindowMask;

    NSRect rect = [MacWindow frameRectForContentRect: frame styleMask: styleMask];

    return CGUL::Vector4F(rect.origin.x, rect.size.height, rect.size.width, rect.origin.y);
}

- (CGUL::Boolean) isFocused
{
    return [window isKeyWindow];
}
@end

#endif
