#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        // Ejecutamos el init original primero
        if (!MenuLayer::init()) return false;

        // Buscamos el menú de botones de la parte inferior
        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            
            // 1. CREAR EL ICONO
            // Cargamos tu imagen personalizada desde la carpeta resources
            auto discordSprite = CCSprite::create("DiscordGDPS.png");

            // Seguridad: Si la imagen no carga, ponemos una por defecto para evitar un crash
            if (!discordSprite) {
                discordSprite = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
            }

            // 2. CREAR EL BOTÓN
            auto discordBtn = CCMenuItemSpriteExtra::create(
                discordSprite,
                this,
                menu_selector(MyMenuLayer::onDiscordClick)
            );

            // 3. ASIGNAR ID Y AGREGAR AL MENÚ
            discordBtn->setID("discord-button-gdps");
            bottomMenu->addChild(discordBtn);

            // 4. RE-ALINEAR LOS BOTONES
            // Esto hace que el nuevo botón se centre junto a los demás automáticamente
            bottomMenu->updateLayout();
        }

        return true;
    }

    // FUNCIÓN QUE SE EJECUTA AL HACER CLICK
    void onDiscordClick(CCObject* sender) {
        // ============================================================
        // COLOCA TU LINK DE DISCORD AQUÍ ABAJO:
        // Reemplaza "https://discord.gg/tu-link" por tu invitación real
        // ============================================================
        
        utils::web::openLinkInBrowser("https://discord.gg/tu-link");

        // ============================================================
    }
};