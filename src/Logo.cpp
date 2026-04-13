#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        auto logo = CCSprite::create("logoStereoDash.png");

        if (logo) {
            logo->setID("stereo-logo-main");
            logo->setScale(0.5f);
            
            //
            logo->setPosition({winSize.width * 0.70f, winSize.height * 0.85f});
            logo->setZOrder(100);
            
            this->addChild(logo);
        }

        return true;
    }
};