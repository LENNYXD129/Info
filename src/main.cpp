#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            
            // 1. Crear el Sprite (la imagen del botón)
            // Puedes usar "GJ_completesIcon_001.png" para un check, o cualquier otro del juego
            auto buttonSprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");

            // 2. Crear el Botón (CCMenuItemSpriteExtra es el estándar de GD para que se hunda al tocarlo)
            auto myButton = CCMenuItemSpriteExtra::create(
                buttonSprite,
                this,
                menu_selector(MyMenuLayer::onMyCustomButton) // La función que se ejecuta al picarle
            );

            // 3. Darle un ID único para que otros mods no se confundan
            myButton->setID("my-custom-button");

            // 4. Agregarlo al menú de abajo
            bottomMenu->addChild(myButton);

            // 5. IMPORTANTE: Recalcular el centro para que el nuevo botón quepa bien
            bottomMenu->updateLayout();
        }

        return true;
    }

    // Esta es la función que se activa cuando presionas el botón
    void onMyCustomButton(CCObject* sender) {
        FLAlertLayer::create(
            "¡Hola!", 
            "Has presionado tu botón personalizado de <cl>Geode</c>.", 
            "OK"
        )->show();
    }
};