#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

#include "chatlogic.h"

class GraphNode; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    std::unique_ptr<wxBitmap> _image{}; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode{nullptr};
    GraphNode *_rootNode{nullptr};
    ChatLogic *_chatLogic{nullptr};

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
  // constructors / destructors
  ChatBot() = default;           // constructor WITHOUT memory allocation
  ChatBot(std::string filename); // constructor WITH memory allocation

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    ChatLogic *GetChatLogicHandle() const { return _chatLogic; }
    wxBitmap *GetImageHandle() { return _image.get(); }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */
