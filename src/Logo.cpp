#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // PRUEBA DE FUEGO: Usamos una imagen que ya trae el juego (el logo de Geode)
        // Si esto aparece, el código está bien y el problema es tu archivo PNG.
        auto logo = CCSprite::createWithSpriteFrameName("geode.loader/geode-logo-outline.png");
        
        // Si no tienes el logo de geode, intentamos con un botón de RobTop
        if (!logo) {
            logo = CCSprite::createWithSpriteFrameName("GJ_downloadsBtn_001.png");
        }

        if (logo) {
            auto winSize = CCDirector::get()->getWinSize();
            logo->setPosition({winSize.width / 2, winSize.height / 2 + 50});
            logo->setZOrder(1000);
            logo->setID("test-logo-geode");
            this->addChild(logo);
            
            log::info("LOG: El logo de prueba se añadio correctamente");
        }

        return true;
    }
};