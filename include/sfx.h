#ifndef SFX_H
#define SFX_H

#include "raylib.h"

// Efeitos sonoros do jogo. Todos são carregados uma vez em LoadSFX e tocados com PlaySFX.
typedef enum SfxId {
    SFX_BOTAO,      // botões (créditos, voltar) e símbolos/números dos cadeados
    SFX_GARRAFA,    // clicar na garrafa
    SFX_LIVRO,      // diário e bilhete
    SFX_INICIO,     // botão JOGAR do menu
    SFX_BAU,        // bau.mp3: cofre aberto com a senha certa
    SFX_PUZZLE,     // finalizarpuzzle.mp3: símbolos da caixa do armário (pega a chave) e estante concluída
    SFX_DIALOGO,    // avançar/fechar uma caixa de diálogo
    SFX_COUNT
} SfxId;

void LoadSFX(void);

void PlaySFX(SfxId id);

void UnloadSFX(void);

#endif //SFX_H
