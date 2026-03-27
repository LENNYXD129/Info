#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/ui/GeodeUI.hpp> // Para interfaces más bonitas

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    // ... tu código anterior de init() para crear el botón de InfoGDPS ...

    void onMyCustomButton(CCObject* sender) {
        // 1. Creamos un mensaje con formato. 
        // Usamos <d> para texto con más espacio y etiquetas de color.
        auto alert = FLAlertLayer::create(
            "Stereo GDPS - Info", 
            "Bienvenido a la comunidad oficial.\n"
            "<cg>Versión:</c> 1.0\n"
            "<cy>Estado:</c> Online\n\n"
            "Aquí puedes encontrar niveles personalizados,\n"
            "eventos semanales y una economía propia.\n"
            "¡Gracias por ser parte de este proyecto!", 
            "Cerrar" // Este es el botón de la izquierda (índice 0)
        );

        // 2. AÑADIR EL BOTÓN DE "SIGUIENTE"
        // Buscamos el menú de botones de la alerta para meter el nuevo
        if (auto buttonMenu = alert->m_buttonMenu) {
            
            auto nextSprite = CCSprite::createWithSpriteFrameName("GJ_arrow01_001.png");
            nextSprite->setScale(0.8f);

            auto nextBtn = CCMenuItemSpriteExtra::create(
                nextSprite,
                this,
                menu_selector(MyMenuLayer::onNextPage) // Función para la página 2
            );
            
            // Lo posicionamos a la derecha del botón "Cerrar"
            nextBtn->setPosition({80, 0}); 
            buttonMenu->addChild(nextBtn);
        }

        alert->show();
    }

    // Función para la segunda página de información
    void onNextPage(CCObject* sender) {
        // Cerramos la alerta anterior (opcional)
        // Luego creamos la nueva página
        FLAlertLayer::create(
            "Reglas y Staff",
            "1. No usar hacks en niveles rated.\n"
            "2. Respetar a los demás usuarios.\n\n"
            "<cp>Admin:</cp> Lennyx\n"
            "<cb>Moderadores:</cb> Equipo Stereo",
            "Volver"
        )->show();
    }
};