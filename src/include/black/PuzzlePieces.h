#pragma once
// PuzzlePieces — chess puzzle piece entities and puzzle animal variants
// Struct layouts from bw1-decomp (PuzzleGame.h)
// 26 types total

#include "Animal.h"
#include "AnimalCow.h"
#include "AnimalHorse.h"
#include "AnimalLion.h"
#include "AnimalPig.h"
#include "AnimalSheep.h"
#include "AnimalTortoise.h"
#include "AnimalWolf.h"
#include "AnimatedStatic.h"
#include "MobileObject.h"
#include "PileFood.h"
#include "Totem.h"

// === ChessGamePuzzle (0x28) — extends GameThingWithPos ===

#include "GameThingWithPos.h"

struct ChessGamePuzzle : public GameThingWithPos {
};
static_assert(sizeof(ChessGamePuzzle) == 0x28, "ChessGamePuzzle size mismatch");

// === ChessPiece hierarchy (all 0x98) — extends AnimatedStatic ===

struct ChessPiece : public AnimatedStatic {
};
static_assert(sizeof(ChessPiece) == 0x98, "ChessPiece size mismatch");

struct ChessKing : public ChessPiece {};
static_assert(sizeof(ChessKing) == 0x98, "ChessKing size mismatch");

struct ChessKnight : public ChessPiece {};
static_assert(sizeof(ChessKnight) == 0x98, "ChessKnight size mismatch");

struct ChessMad : public ChessPiece {};
static_assert(sizeof(ChessMad) == 0x98, "ChessMad size mismatch");

struct ChessPion : public ChessPiece {};
static_assert(sizeof(ChessPion) == 0x98, "ChessPion size mismatch");

struct ChessQueen : public ChessPiece {};
static_assert(sizeof(ChessQueen) == 0x98, "ChessQueen size mismatch");

struct ChessTower : public ChessPiece {};
static_assert(sizeof(ChessTower) == 0x98, "ChessTower size mismatch");

// === Piece* types (all 0x148) — extend specific Animal species ===

struct PieceCow : public Cow {};
static_assert(sizeof(PieceCow) == 0x148, "PieceCow size mismatch");

struct PieceHorse : public Horse {};
static_assert(sizeof(PieceHorse) == 0x148, "PieceHorse size mismatch");

struct PieceLion : public Lion {};
static_assert(sizeof(PieceLion) == 0x148, "PieceLion size mismatch");

struct PiecePig : public Pig {};
static_assert(sizeof(PiecePig) == 0x148, "PiecePig size mismatch");

struct PieceSheep : public Sheep {};
static_assert(sizeof(PieceSheep) == 0x148, "PieceSheep size mismatch");

struct PieceTortoise : public Tortoise {};
static_assert(sizeof(PieceTortoise) == 0x148, "PieceTortoise size mismatch");

struct PieceVillager : public Animal {};
static_assert(sizeof(PieceVillager) == 0x148, "PieceVillager size mismatch");

struct PieceWolf : public Wolf {};
static_assert(sizeof(PieceWolf) == 0x148, "PieceWolf size mismatch");

// === Puzzle* types — extend Piece*/other base types ===

struct PuzzleCow : public PieceCow {};
static_assert(sizeof(PuzzleCow) == 0x148, "PuzzleCow size mismatch");

struct PuzzleHorse : public PieceHorse {};
static_assert(sizeof(PuzzleHorse) == 0x148, "PuzzleHorse size mismatch");

struct PuzzleLion : public PieceWolf {};
static_assert(sizeof(PuzzleLion) == 0x148, "PuzzleLion size mismatch");

struct PuzzlePig : public PiecePig {};
static_assert(sizeof(PuzzlePig) == 0x148, "PuzzlePig size mismatch");

struct PuzzleSheep : public PieceSheep {};
static_assert(sizeof(PuzzleSheep) == 0x148, "PuzzleSheep size mismatch");

struct PuzzleTortoise : public PieceTortoise {};
static_assert(sizeof(PuzzleTortoise) == 0x148, "PuzzleTortoise size mismatch");

struct PuzzleVillager : public PieceVillager {};
static_assert(sizeof(PuzzleVillager) == 0x148, "PuzzleVillager size mismatch");

struct PuzzleGrain : public PileFood {};
static_assert(sizeof(PuzzleGrain) == 0xBC, "PuzzleGrain size mismatch");

struct PuzzleTotem : public Totem {};
static_assert(sizeof(PuzzleTotem) == 0xE4, "PuzzleTotem size mismatch");

struct PuzzleMobileObject : public MobileObject {};
static_assert(sizeof(PuzzleMobileObject) == 0x68, "PuzzleMobileObject size mismatch");
