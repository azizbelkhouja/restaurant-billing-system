# restaurant-billing-system

Questo progetto è un semplice sistema di fatturazione per un ristorante, implementato in C. Il programma permette di generare fatture per i clienti, visualizzare tutte le fatture precedenti, e cercare una fattura specifica per nome del cliente.

## Funzionalità

1. **Genera Fattura**: Permette di inserire i dettagli del cliente e degli articoli acquistati, calcolando il totale e l'IVA, e offre la possibilità di salvare la fattura in un file.
2. **Mostra tutte le Fatture**: Visualizza tutte le fatture salvate precedentemente.
3. **Cerca Fattura**: Permette di cercare una fattura specifica inserendo il nome del cliente.
4. **Esci**: Termina il programma.

## Struttura del Codice

- `struct items`: Struttura per memorizzare i dettagli di un singolo articolo (nome, prezzo, quantità).
- `struct orders`: Struttura per memorizzare un ordine, inclusi i dettagli del cliente, la data e gli articoli ordinati.
- `generateBillHeader()`: Funzione per generare l'intestazione della fattura.
- `generateBillBody()`: Funzione per generare il corpo della fattura.
- `generateBillFooter()`: Funzione per generare il piede della fattura, calcolando il totale e l'IVA.

## Come Eseguire

1. **Compilare il codice**: Utilizzare un compilatore C (ad esempio, `gcc`) per compilare il file sorgente.

    ```bash
    gcc -o ristorante_unife main.c
    ```

2. **Eseguire il programma**:

    ```bash
    ./ristorante_unife
    ```

3. **Seguire le istruzioni sullo schermo** per selezionare l'operazione desiderata.

## Esempio di Utilizzo

1. **Generazione di una Fattura**:

    - Inserire il nome del cliente.
    - Inserire il numero di articoli.
    - Per ogni articolo, inserire il nome, la quantità e il prezzo unitario.
    - Salvare la fattura se desiderato.

2. **Visualizzazione di tutte le Fatture**:

    - Selezionare l'opzione per mostrare tutte le fatture per visualizzare le fatture salvate precedentemente.

3. **Ricerca di una Fattura**:

    - Inserire il nome del cliente per cercare e visualizzare una fattura specifica.

## Dettagli Tecnici

- **Lingua**: C
- **Librerie**: `stdio.h`, `string.h`, `stdlib.h`
- **File di Dati**: Le fatture vengono salvate in un file binario `RestaurantBill.dat`.

## Note

- Il programma utilizza la data corrente al momento della generazione della fattura.
- L'IVA viene calcolata al 7% del totale.


**Autore**: Mohamed Aziz Belkhouja

 
