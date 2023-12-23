import QtQuick
import QtQuick.Controls

import PI.Image

Window {
    id: rootWindow

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

    Button {
        id: addStepButton

        text: "Add new step"

        anchors.top: parent.top
        anchors.right: parent.right

        onClicked: addStepMenu.open()

        Menu {
            id: addStepMenu
            x: rootWindow.width - width
            y: addStepButton.y + addStepButton.height
            transformOrigin: Menu.TopRight

            Action {
                text: "Binarization"
                onTriggered: processor.steps.addStep("bin")
            }

            Action {
                text: "Window Binarization"
                onTriggered: processor.steps.addStep("winbin")
            }
        }
    }

    ListView {
        id: stepsList

        clip: true

        anchors.top: addStepButton.bottom
        anchors.bottom: parent.bottom
        anchors.left: originalImage.right
        anchors.right: parent.right
        anchors.margins: 20

        model: processor.steps

        delegate: ImageProcessingStep {
            width: stepsList.width
            height: 30 * model.display.values.length

            stepName: model.display.name
            stepValues: model.display.values
        }

        onCountChanged: processor.processImage()
    }
}
