#ifndef DRAW_HPP
#define DRAW_HPP

class Draw {
    public:
    float colors[7][3] = {
        {1.0f, 0.0f, 0.0f},        // RED
        {1.0f, 0.5f, 0.0f},        // ORANGE
        {1.0f, 1.0f, 0.0f},        // YELLOW
        {0.5f, 1.0f, 0.0f},        // GREEN
        {0.0f, 1.0f, 1.0f},        // AQUA
        {0.5f, 0.0f, 1.0f},        // PURPLE
        {1.0f, 1.0f, 1.0f}         // WHITE
    };
        Draw() = default;
        ~Draw() = default;
        void DrawSimulateLight();
        void DrawColumnsChanger();
        void DrawRowsChanger();
        void DrawSpeedChanger();
        void DrawColorSquareChanger();
        void DrawColorGridChanger();
    private:
        void DrawUnitSquareColorChanger(int x, int y, int size, int pos);
        void DrawUnitGridColorChanger(int x, int y, int size, int pos);
    };

#endif //DRAW_HPP
