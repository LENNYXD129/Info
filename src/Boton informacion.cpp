#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        // Usamos un pequeño retraso para asegurar que Geode ya cargó sus botones
        this->scheduleOnce(schedule_selector(MyMenuLayer::setupMenu), 0.1f);

        return true;
    }

    void setupMenu(float dt) {
        auto bottomMenu = this->getChildByID("bottom-menu");
        if (!bottomMenu) return;

        // 1. BORRAR EL BOTÓN DE GEODE
        if (auto geodeBtn = bottomMenu->getChildByID("geode.loader/geode-button")) {
            geodeBtn->removeFromParent();
        }

        // 2. AÑADIR TU BOTÓN PERSONALIZADO (InfoGDPS)
        // Usamos CCSprite::create porque es tu propia imagen en resources
        auto buttonSprite = CCSprite::create("info.png");
        
        // Seguridad: Si no encuentra tu imagen, usa una de auxilio
        if (!buttonSprite) {
            buttonSprite = CCSprite::createWithSpriteFrameName("GJ_infoIcon_001.png");
        }

        auto myButton = CCMenuItemSpriteExtra::create(
            buttonSprite,
            this,
            menu_selector(MyMenuLayer::onMyCustomButton)
        );
        myButton->setID("InfoGDPS");

        // Lo agregamos al menú
        bottomMenu->addChild(myButton);

        // 3. RECENTRAR TODO
        bottomMenu->updateLayout();
    }

    // --- ACCIONES DE LOS BOTONES ---

    void onMyCustomButton(CCObject* sender) {
        auto alert = FLAlertLayer::create(
            "Stereo GDPS - Info", 
            "Bienvenido a la comunidad oficial.\n"
            "<cg>Versión:</c> 1.0\n"
            "<cy>Estado:</c> Online\n\n"
            "Usa la flecha para ver más info...", 
            "Cerrar"
        );

        // Añadir flecha de "Siguiente" a la alerta
        if (auto btnMenu = alert->m_buttonMenu) {
            auto nextSpr = CCSprite::createWithSpriteFrameName("GJ_arrow01_001.png");
            nextSpr->setScale(0.7f);
            
            auto nextBtn = CCMenuItemSpriteExtra::create(
                nextSpr,
                this,
                menu_selector(MyMenuLayer::onNextPage)
            );
            nextBtn->setPosition({80, 0});
            btnMenu->addChild(nextBtn);
        }
        alert->show();
    }

    void onNextPage(CCObject* sender) {
        FLAlertLayer::create(
            "Reglas y Staff",
            "1. No usar hacks en niveles rated.\n"
            "2. Respetar a los demás usuarios.\n\n"
            "<cp>Admin:</cp> Lennyx\n"
            "<cb>Moderadores:</cb> Equipo Stereo",
            "OK"
        )->show();
    }
};