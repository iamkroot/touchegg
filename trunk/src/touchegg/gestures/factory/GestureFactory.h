/**
 * @file /src/touchegg/gestures/factory/GestureFactory.h
 *
 * @~spanish
 * Este archivo es parte del proyecto Touchégg, usted puede redistribuirlo y/o
 * modificarlo bajo los téminos de la licencia GNU GPL v3.
 *
 * @~english
 * This file is part of the Touchégg project, you can redistribute it and/or
 * modify it under the terms of the GNU GPL v3.
 *
 * @class  GestureFactory
 * @author José Expósito
 */
#ifndef GESTUREFACTORY_H
#define GESTUREFACTORY_H


#include "src/touchegg/util/Include.h"
#include "src/touchegg/gestures/types/GestureTypeEnum.h"
#include "src/touchegg/gestures/implementations/Gesture.h"

#include "src/touchegg/gestures/implementations/TwoFingersTap.h"
#include "src/touchegg/gestures/implementations/ThreeFingersTap.h"
#include "src/touchegg/gestures/implementations/FourFingersTap.h"
#include "src/touchegg/gestures/implementations/FiveFingersTap.h"

#include "src/touchegg/gestures/implementations/ThreeFingersPinch.h"

#include "src/touchegg/gestures/implementations/TwoFingersDragUp.h"
#include "src/touchegg/gestures/implementations/TwoFingersDragDown.h"
#include "src/touchegg/gestures/implementations/TwoFingersDragLeft.h"
#include "src/touchegg/gestures/implementations/TwoFingersDragRight.h"

#include "src/touchegg/gestures/implementations/ThreeFingersDragUp.h"
#include "src/touchegg/gestures/implementations/ThreeFingersDragDown.h"
#include "src/touchegg/gestures/implementations/ThreeFingersDragLeft.h"
#include "src/touchegg/gestures/implementations/ThreeFingersDragRight.h"

#include "src/touchegg/gestures/implementations/FourFingersDragUp.h"
#include "src/touchegg/gestures/implementations/FourFingersDragDown.h"
#include "src/touchegg/gestures/implementations/FourFingersDragLeft.h"
#include "src/touchegg/gestures/implementations/FourFingersDragRight.h"


/**
 * @~spanish
 * Factoría para crear los distintos gestos.
 *
 * @~english
 * Factory to create the different gestures.
 */
class GestureFactory {

    private:

        /**
         * @~spanish
         * Única instancia de la clase.
         *
         * @~english
         * Single instance of the class.
         */
        static GestureFactory* instance;

        // Hide constructors
        GestureFactory(){}
        GestureFactory(const GestureFactory&){}
        const GestureFactory& operator = (const GestureFactory& gf){return gf;}

    public:

        /**
         * @~spanish
         * Único método para obtener una instancia de la clase.
         * @return La única instancia de la clase.
         *
         * @~english
         * Only method to get an instance of the class.
         * @return The single instance of the class.
         */
        static GestureFactory* getInstance();

        //----------------------------------------------------------------------

        /**
         * @~spanish
         * Crea un gesto con las propiedades indicadas. IMPORTANTE: No olvidar
         * liberar memoria.
         * @param type  Tipo del gesto.
         * @param id    ID del gesto.
         * @param attrs Atributos del gestos, siendo la clave el nombre del
         *        atributo (por ejemplo "focus x", "touches"...) y el valor el
         *        valor del propio atributo.
         * @return El gesto.
         *
         * @~english
         * Creates a gesture with the specified properties. IMPORTANT: Don't
         * forget to free memory.
         * @param type  Gesture type.
         * @param id    Gesture ID.
         * @param attrs Gesture attributes, where the key is the name of the
         *        attribute (ie "focus x", "touches") and the value the value of
         *        the attribute.
         * @param The gesture.
         */
        Gesture* createGesture(GeisGestureType type, GeisGestureId id,
            QHash<QString, QVariant> attrs);

};

#endif // GESTUREFACTORY_H