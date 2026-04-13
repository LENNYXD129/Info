#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        //
        auto logo = CCSprite::create("logoStereoDash.png");

        //
        if (!logo) {
            logo = CCSprite::createWithSpriteFrameName("GJ_playBtn_001.png");
        }

        if (logo) {
            logo->setID("stereo-logo-fix");
            logo->setScale(0.5f);
            
            //
            logo->setPosition({winSize.width * 0.72f, winSize.height * 0.82f});
            
            this->addChild(logo, 1000);
        }

        return true;
    }
};