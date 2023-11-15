import QtQuick 2.0
import QtQuick.Controls

Item {
    id: baseStep

    property bool stepEnabled
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

    Binding {
        baseStep.stepEnabled: stepCheckbox.checked
    }
}
