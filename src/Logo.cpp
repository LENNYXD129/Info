#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        //
        auto fullPath = CCFileUtils::get()->fullPathForFilename("logo Stereo Dash.png", false);
        auto logo = CCSprite::create(fullPath.c_str());

        if (logo) {
            logo->setID("stereo-logo-main");
            logo->setScale(0.5f);
            
            //
            logo->setPosition({winSize.width * 0.72f, winSize.height * 0.82f});
            logo->setZOrder(100);
            
            this->addChild(logo);
        } else {
            //
            log::error("No se encontro la imagen en la carpeta del juego: logo Stereo Dash.png");
        }

        return true;
    }
};