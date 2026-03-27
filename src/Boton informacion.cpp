#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            
            // --- AQUÍ ESTÁ EL CAMBIO ---
            // Usamos CCSprite::create para cargar tu archivo "info.png" directamente
            // desde la carpeta resources de tu mod.
            // Asegúrate de que el nombre coincida (info.png o info.jpeg).
            auto buttonSprite = CCSprite::create("info.png");

            // SEGURIDAD: Si no encuentra tu imagen, usa una del juego para no crashar
            if (!buttonSprite) {
                FLAlertLayer::create("Error", "No se encontró resources/info.png", "OK")->show();
                buttonSprite = CCSprite::createWithSpriteFrameName("GJ_plusBtn_001.png");
            }
            // -----------------------------

            // 2. Crear el Botón con el estándar de GD
            auto myButton = CCMenuItemSpriteExtra::create(
                buttonSprite,
                this,
                menu_selector(MyMenuLayer::onMyCustomButton)
            );

            // 3. Darle un ID único
            myButton->setID("InfoGDPS");

            // 4. Agregarlo al menú de abajo
            bottomMenu->addChild(myButton);

            // 5. Recalcular el centro
            bottomMenu->updateLayout();
        }

        return true;
    }

    void onMyCustomButton(CCObject* sender) {
        FLAlertLayer::create(
            "¡Bienvenido!", 
            "Este es el Stereo GDPS", 
            "OK"
        )->show();
    }
};