#include "Keyboard.h"
#include <unordered_map>
namespace Hades
{
std::string KeyToString(EKey key)
{
    static const std::unordered_map<EKey, std::string> key_map = {
        { EKey::Backspace, "Backspace" },
        { EKey::Return, "Return" },
        { EKey::Tab, "Tab" },
        { EKey::Shift_L, "Shift_L" },
        { EKey::Shift_R, "Shift_R" },
        { EKey::Escape, "Escape" },
        { EKey::Space, "Space" },
        { EKey::Key_0, "0" },
        { EKey::Key_1, "1" },
        { EKey::Key_2, "2" },
        { EKey::Key_3, "3" },
        { EKey::Key_4, "4" },
        { EKey::Key_5, "5" },
        { EKey::Key_6, "6" },
        { EKey::Key_7, "7" },
        { EKey::Key_8, "8" },
        { EKey::Key_9, "9" },
        { EKey::A, "A" },
        { EKey::B, "B" },
        { EKey::C, "C" },
        { EKey::D, "D" },
        { EKey::E, "E" },
        { EKey::F, "F" },
        { EKey::G, "G" },
        { EKey::H, "H" },
        { EKey::I, "I" },
        { EKey::J, "J" },
        { EKey::K, "K" },
        { EKey::L, "L" },
        { EKey::M, "M" },
        { EKey::N, "N" },
        { EKey::O, "O" },
        { EKey::P, "P" },
        { EKey::Q, "Q" },
        { EKey::R, "R" },
        { EKey::S, "S" },
        { EKey::T, "T" },
        { EKey::U, "U" },
        { EKey::V, "V" },
        { EKey::W, "W" },
        { EKey::X, "X" },
        { EKey::Y, "Y" },
        { EKey::Z, "Z" },
        { EKey::F1, "F1" },
        { EKey::F2, "F2" },
        { EKey::F3, "F3" },
        { EKey::F4, "F4" },
        { EKey::F5, "F5" },
        { EKey::F6, "F6" },
        { EKey::F7, "F7" },
        { EKey::F8, "F8" },
        { EKey::F9, "F9" },
        { EKey::F10, "F10" },
    };

    auto it = key_map.find(key);
    if (it != key_map.end())
    {
        return it->second;
    }
    return "Unknown key";
}

}
