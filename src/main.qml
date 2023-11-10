import QtQuick
import QtQuick.Controls

import PI.Image

Window {
    width: 900
    height: 700
    maximumHeight: height
    maximumWidth: width

    minimumHeight: height
    minimumWidth: width

    visible: true
    title: qsTr("Hepatic Steatosis")

    CustomImage {
        id: originalImage

        image: processor.provider.originalImage

        width: 300
        height: 300

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 20
    }

    CustomImage {
        id: finalImage

        image: processor.provider.finalImage

        width: 300
        height: 300

        anchors.left: parent.left
        anchors.top: originalImage.bottom
        anchors.margins: 20
    }

    ImageProcessingStep {
        id: binarizationStep

        anchors.top: parent.top
        anchors.left: originalImage.right
        anchors.margins: 20

        stepFrom: 0
        stepTo: 255

        stepName: "Binarize Threshold:"
    }

    ImageProcessingStep {
        id: contrastStep

        anchors.top: binarizationStep.top
        anchors.left: originalImage.right
        anchors.margins: 20
        anchors.topMargin: 50

        stepFrom: 10
        stepTo: 20

        stepName: "Contrast enhance:"
    }

    Component.onCompleted: {
        processor.binarizationEnabled = Qt.binding(function() { return  binarizationStep.stepEnabled })
        processor.binarizationThreshold = Qt.binding(function() { return binarizationStep.stepValue })
    }
}
