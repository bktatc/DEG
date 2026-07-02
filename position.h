#ifndef POSITION_H
#define POSITION_H

#include <algorithm>
#include <string>

class Position {
    public:
        Position();
        double lat{};
        double lon{};
        double alt{};
        double X{};
        double Y{};
        int dir{0}; //used for specifying heading on stand/lineup
        std::string rwy{};  //for final points
        int dme{};  //for final points
        int idx{};  //for final points
};

#endif // POSITION_H
