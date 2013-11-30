#include <CGUL.hpp>
using namespace CGUL;

#include <iostream>

int main()
{
    WindowStyle style;
    style.title = U8("CGUL Window");
    style.size = UCoord32(640, 480);
    style.backgroundColor = Colors::red;
    style.resizable = false;

    Window window;
    window.Create(style);

    std::cout << "== Style ==" << std::endl;
    std::cout << window.GetStyle() << std::endl;
    std::cout << std::endl;

    URect32 frameExtents = window.GetFrameSize();
    std::cout << "== Frame Extents ==" << std::endl;
    std::cout << "Left Border:      " << frameExtents.x << std::endl;
    std::cout << "Top Border:       " << frameExtents.y << std::endl;
    std::cout << "Right Border:     " << frameExtents.z << std::endl;
    std::cout << "Bottom Border:    " << frameExtents.w << std::endl;

    float hue = 0;
    Timer timer;
    while (window.IsOpen())
    {
        Window::Update();

        hue += timer.GetDeltaTime() * 45;
        if (window.IsFocused())
        {
            window.SetBackgroundColor(Color::MakeHSL(hue, 255, 255));
        }
        else
        {
            window.SetBackgroundColor(Color::MakeHSL(hue, 150, 150));
        }
        if (hue >= 360)
        {
            hue -= 360;
        }

        CGUL::Timer::Sleep(1);
    }
}
