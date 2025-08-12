#include "raylib.h"
#include <stdbool.h>

#define NUM_CAIXAS 4 // Total de caixas disponíveis
#define NUM_SIMBOLOS 10 // Total de símbolos disponíveis

typedef struct {
    Rectangle area;
    int simboloIndex;
} Caixa;

bool VerificarSenha(Caixa caixas[], int senha[]) {
    for (int i = 0; i < NUM_CAIXAS; i++) {
        if (caixas[i].simboloIndex != senha[i]) return false;
    }
    return true;
}

int main() {
    const int screenWidth = 1280;  // Largura da janela
    const int screenHeight = 720; // Altura da janela
    InitWindow(screenWidth, screenHeight, "Puzzle das Caixas"); // Título da janela

    // Backgrounds
    Texture2D backgroundInicial = LoadTexture("ZoomCaixaArmario.png");
    Texture2D backgroundFinal = LoadTexture("ZoomPirata.png");

    // Nomes dos arquivos dos símbolos
    const char *simbolosNomes[NUM_SIMBOLOS] = {
        "SimboloTubarao.png", "SimboloGancho.png", "SimboloCifrao.png", "SimboloX.png", "SimboloEspada.png",
        "SimboloRosa.png", "ZoomPirata.png", "extra.png", "SimboloAncora.png", "SimboloLula.png"
    };

    // Carrega as texturas dos símbolos em um loop
    Texture2D simbolos[NUM_SIMBOLOS];
    for (int i = 0; i < NUM_SIMBOLOS; i++) {
        simbolos[i] = LoadTexture(simbolosNomes[i]);
        // Adicionar uma verificação aqui seria uma boa prática para garantir que o arquivo foi carregado
    }

    // Caixas
    Caixa caixas[NUM_CAIXAS] = {
        {{400, 300, 100, 100}, 0},
        {{550, 300, 100, 100}, 0},
        {{700, 300, 100, 100}, 0},
        {{850, 300, 100, 100}, 0}
    };

    // Botão
    Rectangle botaoConfirmar = {600, 100, 80, 80};

    // Senha
    int senha[NUM_CAIXAS] = {3, 9, 0, 8}; // X, Lula, Tubarão, Âncora
    bool acertou = false;

    SetTargetFPS(60); // Define a taxa de quadros
    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition(); // Posição do mouse

        if (!acertou && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) { // Verifica se o botão esquerdo do mouse foi pressionado
            // Verifica colisão com o botão
            // Primeiro testa botão
            if (CheckCollisionPointRec(mousePos, botaoConfirmar)) { // Se o botão foi clicado

                // Verifica se a senha está correta usando a função VerificarSenha
                if (VerificarSenha(caixas, senha)) {
                    acertou = true;
                }
            } else {
                // Depois testa caixas
                for (int i = 0; i < NUM_CAIXAS; i++) {
                    if (CheckCollisionPointRec(mousePos, caixas[i].area)) {
                        caixas[i].simboloIndex = (caixas[i].simboloIndex + 1) % NUM_SIMBOLOS;
                    }
                }
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (!acertou) {
            DrawTexture(backgroundInicial, 0, 0, WHITE); // Desenha o background inicial (ZoomCaixaArmario.jpeg)

            // Caixas
            for (int i = 0; i < NUM_CAIXAS; i++) {
                DrawTexturePro( // Desenha cada caixa com o símbolo correspondente
                    simbolos[caixas[i].simboloIndex],
                    (Rectangle){0, 0, simbolos[caixas[i].simboloIndex].width, simbolos[caixas[i].simboloIndex].height},
                    caixas[i].area,
                    (Vector2){0, 0},
                    0,
                    WHITE
                );
            }

            // Botão circular
            DrawCircle(botaoConfirmar.x + botaoConfirmar.width/2, 
                       botaoConfirmar.y + botaoConfirmar.height/2, 
                       botaoConfirmar.width/2, 
                       LIGHTGRAY);
            // Centraliza o texto "OK" no botão
            const char* text = "OK";
            int fontSize = 20;
            Vector2 textSize = MeasureTextEx(GetFontDefault(), text, fontSize, 1);
            DrawText(text, botaoConfirmar.x + (botaoConfirmar.width - textSize.x) / 2, 
                           botaoConfirmar.y + (botaoConfirmar.height - textSize.y) / 2, fontSize, BLACK);

        } else {
            DrawTexture(backgroundFinal, 0, 0, WHITE);
        }

        EndDrawing(); 
    }

    // Libera memória
    UnloadTexture(backgroundInicial);
    UnloadTexture(backgroundFinal);
    for (int i = 0; i < NUM_SIMBOLOS; i++) {
        UnloadTexture(simbolos[i]);
    }

    CloseWindow();
    return 0;
}