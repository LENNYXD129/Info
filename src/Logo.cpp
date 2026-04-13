#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        //
        auto topRightMenu = this->getChildByID("top-right-menu");
        
        if (topRightMenu) {
            auto logo = CCSprite::create("logo Stereo Dash.png");
            
            if (logo) {
                logo->setID("stereo-logo");
                logo->setScale(0.5f);
                
                // 
                //
                logo->setPosition({-60, 0}); 
                
                topRightMenu->addChild(logo);
                topRightMenu->updateLayout();
            }
        } else {
            //
            auto winSize = CCDirector::get()->getWinSize();
            auto logo = CCSprite::create("logo Stereo Dash.png");
            if (logo) {
                logo->setPosition({winSize.width * 0.75f, winSize.height * 0.85f});
                this->addChild(logo, 100);
            }
        }

        return true;
    }
};