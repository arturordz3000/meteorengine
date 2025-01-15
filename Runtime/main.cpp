#include "Core/Application.h"

int main() {
    std::unique_ptr<Meteor::Application> application = std::make_unique<Meteor::Application>();

    application->Run();

    return 0;
}