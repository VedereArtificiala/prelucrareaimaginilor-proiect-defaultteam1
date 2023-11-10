import QtQuick 2.0
import QtQuick.Controls

Item {
    id: baseStep

    property int stepValue
    property bool stepEnabled

    property int stepTo
    property int stepFrom

    property string stepName

    Text {
        id: stepTip

        text: stepName

        anchors.left: parent.left
        anchors.top: parent.top
        anchors.margins: 10
    }

    CheckBox {
        id: stepCheckbox

        anchors.left: stepTip.right
        anchors.verticalCenter: stepTip.verticalCenter
        anchors.margins: 10

        checked: baseStep.stepEnabled
    }

    Slider {
        id: stepSlider

        width: 300

        anchors.left: stepCheckbox.right
        anchors.verticalCenter: stepTip.verticalCenter
        anchors.margins: 10

        enabled: baseStep.stepEnabled

        from: baseStep.stepFrom
        value: baseStep.stepValue
        to: baseStep.stepTo
        stepSize: 1.0
    }

    Text {
        id: stepValueBox

        anchors.left: stepSlider.right
        anchors.verticalCenter: stepTip.verticalCenter
        anchors.margins: 10

        text: baseStep.stepValue
    }

    Binding {
        baseStep.stepEnabled: stepCheckbox.checked
    }

    Binding {
        baseStep.stepValue: stepSlider.value
    }
}
