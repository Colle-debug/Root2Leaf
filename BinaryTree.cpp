#include "BinaryTree.h"
using namespace std;

Node* generateRandomBinaryTree(int guaranteedLevels, int maxDepth, int startingDepth) { // Genera albero casuale
    if (startingDepth > guaranteedLevels && (rand() % 2) == 0) {
        return nullptr;
    }

    Node* root = new Node(rand() % 99); // Valori da 0 a 99
    if (startingDepth < maxDepth) { // quando startingDepth = maxDepth, non viene più chiamata la funzione sui figli del nodo al livello maxDepth, la generazione si arresta
        root->left = generateRandomBinaryTree(guaranteedLevels, maxDepth, startingDepth + 1);
        root->right = generateRandomBinaryTree(guaranteedLevels, maxDepth, startingDepth + 1);
    }

    return root;
}

void deallocateTree(Node* root) { // In maniera ricorsiva, dealloco albero precedente ogni qual volta ne creo uno nuovo
    if (root == nullptr) {
        return;
    }
    deallocateTree(root->left);
    deallocateTree(root->right);
    delete root;
}

void visualizeTree(Node* root, QGraphicsScene &scene, int x, int y, int xOffset, int yOffset) {
    if (root != nullptr) {
        // QGraphicsEllipseItem con w = h --> Cerchio!
        QGraphicsEllipseItem* circle = scene.addEllipse(x - 15, y - 15, 30, 30); // Dal centro della vista, lo metto a -15, -15, in modo che poi con raggio 30 risulti centrato
        if (root->maxPath) // Se il nodo appartiene al percorso a somma massima lo coloro di verde scuro (è un albero!)
            circle->setBrush(QBrush(Qt::darkGreen));

        QGraphicsTextItem* text = scene.addText(QString::number(root->data));
        if(QString::number(root->data).length() == 1){
            text->setPos(x - 8, y - 12);
        }else{
            text->setPos(x - 12, y - 12); // Posiziono il testo al centro del cerchio
        }
        QFont font("Arial", 12);
        text->setFont(font);

        if (root->left != nullptr) { // Ricorsivamente disegno i figli sinistri e destri qualora esistessero
            scene.addLine(x, y + 15, x - xOffset, y + yOffset - 15); // y + 15 e yOffset - 15 per non far entrare la linea nei cerchi
            visualizeTree(root->left, scene, x - xOffset, y + yOffset, xOffset / 2, yOffset);
        }
        if (root->right != nullptr) {
            scene.addLine(x, y + 15, x + xOffset, y + yOffset - 15); // Offset è di quanto spostato a destra/sinistra è il figlio rispetto a padre, sia lungo x che lungo y
            visualizeTree(root->right, scene, x + xOffset, y + yOffset, xOffset / 2, yOffset); // Offset sulla X si fa sempre più piccolo (per far entrare tutto nella finestra)
        }
    }
}

void refreshTree(QGraphicsScene &scene, int guaranteedLevels, int maxDepth) {
    scene.clear();
    vector<int> path;
    Node* root = generateRandomBinaryTree(guaranteedLevels, maxDepth, 1);

    int sum = maxR2L(root);
    printPath(root, sum, path);
    std::cout<<"\n";
    std::cout.flush();

    visualizeTree(root, scene, 720, 100, 300, 100);

    // Utilities grafiche: stampa dei valori ottenuti sopra.
    QGraphicsTextItem* maxSumText = scene.addText("Il percorso a somma massima vale " + QString::number(sum));
    QString pathString = "Il percorso a somma massima è ";
        for(int i = path.size() - 1; i >= 0; i--){ // Scorro path al contario perché i nodi al suo interno sono salvati dalle foglie a salire
        pathString += QString::number(path[i]) + " ";
    }

    QGraphicsTextItem* pathText = scene.addText(pathString);
    QGraphicsTextItem* aboutText = scene.addText("Vincenzo Colle - TDP - A.A. 2022/23");
    QFont fontA("Arial", 20);
    QFont fontB("Arial", 10, 5);// Imposto un carattere più piccolo
    maxSumText->setFont(fontA);
    pathText->setFont(fontA);
    aboutText->setFont(fontB);

    // Fissa la posizione dei testi nella scena 1280x720
    maxSumText->setPos(720 - maxSumText->boundingRect().width() / 2, 0);
    pathText->setPos(720 - pathText->boundingRect().width() / 2, maxSumText->boundingRect().height());
    aboutText->setPos(720 - aboutText->boundingRect().width() / 2, maxSumText->boundingRect().height() - 11); // Lo metto nello spazio fra le due scritte grandi

    deallocateTree(root);
    root = nullptr;
}

// Mia reimplemntazione di max2RL
int maxR2L(Node* root) {
    if (!root) {
        return 0;
    }

    int leftSum = maxR2L(root->left);
    int rightSum = maxR2L(root->right);

    int currentSum = max(leftSum, rightSum) + root->data;

    return currentSum;
}

// Mia reimplementazione di printPath
bool printPath(Node* root, int sum, vector<int>& path) {
    if (sum == 0 && root == nullptr) {
        return true;
    }

    if (root == nullptr) {
        return false;
    }

    bool left = printPath(root->left, sum - root->data, path);
    bool right = printPath(root->right, sum - root->data, path);

    if (left || right) {
        root->maxPath = true;
        path.push_back(root->data); // Ogni volta faccio push_back per avere array ordinato con nodi da radice a foglia.
    }

    return left || right;
}




