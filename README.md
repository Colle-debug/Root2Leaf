# Root2Leaf 🌳

**Root2Leaf** è un'applicazione C++ che esplora alberi binari generati casualmente, identificando il cammino da radice a foglia con la massima somma di valori.

## 1. generateRandomBinaryTree 🌱

Genera un albero binario casuale con parametri controllati. La funzione accetta due parametri importanti:
- `guaranteedLevels`: il numero di livelli garantiti dell'albero, assicurando che l'albero abbia almeno questa profondità.
- `maxDepth`: la massima profondità dell'albero, controllando la ricorsione e garantendo che l'albero non superi questa profondità.

## 2. visualizeTree 🌐

Visualizza graficamente l'albero binario utilizzando la libreria `QGraphicsScene`. I nodi appartenenti al percorso con la massima somma vengono evidenziati in verde scuro per una chiara identificazione.

## 3. refreshTree 🔄

Aggiorna l'interfaccia grafica eliminando la visualizzazione precedente e generando un nuovo albero casuale con `generateRandomBinaryTree`. Successivamente, analizza il percorso radice-foglia con la massima somma utilizzando la funzione `maxR2L`.

## 4. maxR2L 🚀

Calcola la massima somma del percorso da radice a foglia utilizzando un approccio ricorsivo. L'algoritmo calcola e restituisce la somma massima possibile.

## 5. printPath 📜

Memorizza e stampa il percorso con la massima somma. Durante la visualizzazione dell'albero, questa funzione evidenzia i nodi appartenenti al percorso massimo.

## Utilizzo

Compila il codice sorgente C++ e esegui il programma. L'interfaccia grafica mostrerà l'albero binario generato e fornirà informazioni sulla somma massima del percorso e il percorso stesso.

## Requisiti

- Compilatore C++ compatibile con le specifiche C++11.
- Libreria grafica Qt per la visualizzazione interattiva.

## Autore 🖋️

Vincenzo Colle

🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
🌳                                                                                                          🌳
🌳 *Progetto sviluppato per l'esame di Tecniche di Programmazione - A.A. 2022/23 - Prof. Bria Alessandro*    🌳
🌳                                                                                                           🌳
🌳 *Vincenzo Colle - Università degli Studi di Cassino e deL Lazio Meridionale*                              🌳
🌳                                                                                                           🌳
🌳 Grazie per aver utilizzato **Root2Leaf**! 🌿                                                             🌳
🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳🌳
