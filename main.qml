import QtQuick 2.1
import com.myself 1.0

Rectangle {
    id: rectangle
    color: "white"
//    anchors.fill: parent
    width: 200
    height: 200


    Text {
        id: text
        text: "QML code.\n(Click to close)"
        font.pointSize: 14
        anchors.centerIn: parent
        PropertyAnimation {
            id: animation
            target: text
            property: "rotation"
            from: 0; to: 360; duration: 5000
            loops: Animation.Infinite
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: myObject.reopen_main_window()
        //onClicked: animation.paused ? animation.resume() : animation.pause()
    }
    Component.onCompleted: animation.start()
}
