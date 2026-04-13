#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Cargamos el logo
        auto logo = CCSprite::create("logo Stereo Dash.png");

        if (logo) {
            auto mainTitle = this->getChildByID("main-title");

            if (mainTitle) {
                auto titlePos = mainTitle->getPosition();
                auto titleSize = mainTitle->getContentSize();

                // Alineamos debajo a la izquierda del título
                logo->setAnchorPoint({0.0f, 0.5f}); 
                logo->setPosition({titlePos.x - (titleSize.width / 2), titlePos.y - 40.0f});
            }

            logo->setScale(0.4f);
            logo->setZOrder(100);
            logo->setID("stereo-dash-logo");

            this->addChild(logo);
        }

        return true;
    }
};