import QtQuick 2.0
import QtQuick.Controls
import QtQuick.Layouts

Item {
    id: baseStep

    property string stepName
    property var stepValues

    Button {
        id: deleteStepButton

        text: "Delete"

        anchors.left: parent.left
        anchors.verticalCenter: stepValues.verticalCenter
        anchors.margins: 20

        onClicked: processor.steps.deleteStep(index)
    }

    Text {
        id: stepTip

        text: stepName

        anchors.left: deleteStepButton.right
        anchors.verticalCenter: stepValues.verticalCenter
        anchors.margins: 20
    }

    ListView {
        id: stepValues

        implicitHeight: contentItem.childrenRect.height

        clip: true

        anchors.left: stepTip.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.margins: 15

        model: baseStep.stepValues

        delegate: RowLayout {
            width: parent.width

            Slider {
                id: stepValueSlider

                Layout.fillWidth: true

                from: modelData.minValue
                value: modelData.currentValue
                to: modelData.maxValue
                stepSize: 1.0

                onValueChanged: {
                    modelData.currentValue = value
                    processor.processImage()
                }
            }

            Text {
                id: stepValueTextBox

                text: modelData.currentValue
            }

            Text {
                id: stepValueName

                text: modelData.name
            }
        }
    }
}
