#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5
#define MAX_SENTENCES 25
#define MAX_WORDS 25
    
char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) {
return document[k - 1];
}

char**** get_document(char* str) {
char**** doc = malloc(MAX_PARAGRAPHS * sizeof(char***));

for (int p = 0; p < MAX_PARAGRAPHS; p++) {
    *(doc + p) = malloc(MAX_SENTENCES * sizeof(char**));

    for (int s = 0; s < MAX_SENTENCES; s++) {
        *(*(doc + p) + s) = malloc(MAX_WORDS * sizeof(char*));

        for (int w = 0; w < MAX_WORDS; w++) {
                *(*(*(doc + p) + s) + w) = malloc(MAX_CHARACTERS * sizeof(char));
        }
    }
}

char para[25][3125];
char sent[625][625];

int s_to_p[625];

int p_ptr = 0;
char *p = strtok(str, "\n");

while (p != NULL) {
        if (strlen(p) != 0) {
                strcpy(para[p_ptr], p);
                p_ptr++;
        }
        p = strtok(NULL, "\n");
}

int s_ptr = 0;
for (int p_itr = 0; p_itr < p_ptr; p_itr++) {
        char *s = strtok(para[p_itr], ".");

        while (s != NULL) {
                if (strlen(s) != 0) {
                        strcpy(sent[s_ptr], s);
                        s_to_p[s_ptr] = p_itr;
                        s_ptr++;
                }

                s = strtok(NULL, ".");
        }
}

int temp = 0;
for (int s_itr = 0; s_itr < s_ptr; s_itr++) {
        int w_ptr = 0;
        char *w = strtok(sent[s_itr], " ");

        if (s_itr > 0 && (s_to_p[s_itr] != s_to_p[s_itr - 1])) {
                temp = 0;
        }

        while(w != NULL) {
                if (strlen(w) != 0) {
                        strcpy(doc[s_to_p[s_itr]][temp][w_ptr], w);
                        w_ptr++;
                }

                w = strtok(NULL, " ");
        }

        temp++;
}


return doc;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}