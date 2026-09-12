#include "../Engine/Source/Core/Logging/Log.h"
#include "Source/Core/Logging/Sink.h"
#include "Source/Utility/Paths.h"
#include <memory>

int main(int argc, char* argv[])
{
    if (!Hades::CPaths::Initialize())
    {
        return 1;
    }
    Hades::CLogger::Get().RegisterSink(std::make_unique<Hades::CConsoleSink>());
    Hades::CLogger::Get().RegisterSink(std::make_unique<Hades::CFileSink>());

    HADES_LOG(Log, "Test");
    HADES_LOG(Warning, "Test %i", 32);
    HADES_LOG(Error, "Test %f", 64.32f);
    HADES_LOG(Fatal, "Test %d", 34.0202f);
    HADES_LOG(Log, "%s", "Test");

    return 0;
}
