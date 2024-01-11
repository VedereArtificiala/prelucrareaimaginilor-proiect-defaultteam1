import QtQuick
import QtQuick.Controls

import PI.Image

Window {
    id: rootWindow

    width: 1000
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

    CheckBox {
        id: calculateDiagnosisCheckbox

        text: "Calculate Diagnosis"
        checked: processor.askedForDiagnosis
        visible:stepsList.count > 0

        anchors.top: parent.top
        anchors.right: addStepButton.left
        anchors.margins: 20

        onCheckedChanged: {
            processor.askedForDiagnosis = checked;
            processor.processImage()
        }
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

            Action {
                text: "Blur"
                onTriggered: processor.steps.addStep("blur")
            }

            Action {
                text: "Change Luminosity"
                onTriggered: processor.steps.addStep("luminosity")
            }

            Action {
                text: "Normalize"
                onTriggered: processor.steps.addStep("norm")
            }

            Action {
                text: "Noise Reduction"
                onTriggered: processor.steps.addStep("noisered")
            }

            Action {
                text: "Morphological Operations"
                onTriggered: processor.steps.addStep("morphologic")
            }
        }
    }

    ListView {
        id: stepsList

        clip: true

        anchors.top: addStepButton.bottom
        anchors.bottom: diagnosisResultText.top
        anchors.left: originalImage.right
        anchors.right: parent.right
        anchors.margins: 20

        model: processor.steps

        delegate: ImageProcessingStep {
            width: stepsList.width
            height: 30 * model.display.values.length + 30

            stepName: model.display.name
            stepValues: model.display.values
        }

        onCountChanged: processor.processImage()
    }

    Text {
        id: diagnosisResultText

        anchors.bottom:parent.bottom
        anchors.left: finalImage.right
        anchors.right: parent.right
        anchors.margins: 20
        anchors.bottomMargin: 50

        visible: processor.askedForDiagnosis

        text: "Diagnosis Result: " + processor.diagnosisResult.result + " (%)"
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pointSize: 15
    }
}
