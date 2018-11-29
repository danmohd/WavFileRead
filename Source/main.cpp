#include "WavFile.hpp"

int main()
{
    WavFile file;
    file.load("../TestAudio.wav");
    file.readHeader();

    return 0;
}
