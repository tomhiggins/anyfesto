<?php
// $Id: chess.inc,v 1.2 2004/11/09 09:32:16 dadij Exp $

#  These php3 scripts are freeware.
#  That means, you may use and change it freely for any purpose.
#  However, please send an email to the author
#  (http://www.mailchess.de/chessphpfeedback.html)
#  if you use this script in any way.

#  This software is provided 'as-is',
#  without any express or implied warranty.
#  In no event the author will be held liable
#  for any damages arising from the use of this software.

#  Please send comments or bug reports to http://www.mailchess.de/chessphpfeedback.html



# These variables are set before a move is verified or executed

$nkmove_from_Square = 0;
$nkmove_to_Square = 0;
$nkmove_promotion_figur = 0;


# These variables are set after each execution of a move
# They describe the status of position

$nkmove_ep_Square = 0;
$nkmove_turn = 1;
$nkmove_castling_ws = TRUE;
$nkmove_castling_wl = TRUE;
$nkmove_castling_bs = TRUE;
$nkmove_castling_bl = TRUE;
$nkmove_PlyNumber = 0;


# Variables for the move list
# Only used in move_count

$nkmove_list_from = array(200);
$nkmove_list_to = array(200);
$nkmove_list_count = 0;

# For creating the notation
$nkpgn_piece = "";
$nkpgn_from_digit = "";
$nkpgn_from_letter = "";
$nkpgn_capture = FALSE;
$nkpgn_square_list = array(8);  // For writing Sge2 (if two or more pieces can enter a square)

# For handling of result when mate or so

$nkState = 0;

# How a piece can move

$nkab_Bishop = array(-9, -11, 9, 11);
$nkab_Rook   = array(-1, 10, 1, -10);
$nkab_Knight = array(19, 21, 12, -8, -19, -21, -12, 8);
$nkab_Queen  = array(-9, -11, 9, 11, -1, 10, 1, -10);
$nkab_King   = array(-9, -11, 9, 11, -1, 10, 1, -10);

# Constants for get_GameState()

define("gsRunning" , 0);
define("gsMate" , 1);
define("gsStalemate" , 2);
define("gsCheck" , 3);

# The values of the pieces

define("WK" , 6);    define("BK" , -6);
define("WQ" , 5);    define("BQ" , -5);
define("WR" , 2);    define("BR" , -2);
define("WB" , 3);    define("BB" , -3);
define("WN" , 4);    define("BN" , -4);
define("WP" , 1);    define("BP" , -1);


# The values of the squares

define("sq_a1",21);define("sq_b1",22);define("sq_c1",23);define("sq_d1",24);
define("sq_a2",31);define("sq_b2",32);define("sq_c2",33);define("sq_d2",34);
define("sq_a3",41);define("sq_b3",42);define("sq_c3",43);define("sq_d3",44);
define("sq_a4",51);define("sq_b4",52);define("sq_c4",53);define("sq_d4",54);
define("sq_a5",61);define("sq_b5",62);define("sq_c5",63);define("sq_d5",64);
define("sq_a6",71);define("sq_b6",72);define("sq_c6",73);define("sq_d6",74);
define("sq_a7",81);define("sq_b7",82);define("sq_c7",83);define("sq_d7",84);
define("sq_a8",91);define("sq_b8",92);define("sq_c8",93);define("sq_d8",94);

define("sq_e1",25);define("sq_f1",26);define("sq_g1",27);define("sq_h1",28);
define("sq_e2",35);define("sq_f2",36);define("sq_g2",37);define("sq_h2",38);
define("sq_e3",45);define("sq_f3",46);define("sq_g3",47);define("sq_h3",48);
define("sq_e4",55);define("sq_f4",56);define("sq_g4",57);define("sq_h4",58);
define("sq_e5",65);define("sq_f5",66);define("sq_g5",67);define("sq_h5",68);
define("sq_e6",75);define("sq_f6",76);define("sq_g6",77);define("sq_h6",78);
define("sq_e7",85);define("sq_f7",86);define("sq_g7",87);define("sq_h7",88);
define("sq_e8",95);define("sq_f8",96);define("sq_g8",97);define("sq_h8",98);


# The board variable
# It is surrounded by "edge values"; empty squares are 0

$nkfirst_Position  = array(
  100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,
  100,WR ,WN ,WB ,WQ ,WK ,WB ,WN ,WR ,100,
  100,WP ,WP ,WP ,WP ,WP ,WP ,WP ,WP ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,BP ,BP ,BP ,BP ,BP ,BP ,BP ,BP ,100,
  100,BR ,BN ,BB ,BQ ,BK ,BB ,BN ,BR ,100,
  100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100);

$nkempty_Position  = array(
  100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,0  ,0  ,0  ,0  ,0  ,0  ,0  ,0  ,100,
  100,100,100,100,100,100,100,100,100,100,
  100,100,100,100,100,100,100,100,100,100);


$nkBoard = array(120);

$nkNotation = "";
$pgn_Move = "";  // last move is inserted into the mail separately

# Only for debugging

function print_Position() {
         global $nkBoard;
         for ($nki = 11; $nki >= 0; $nki--) {
             for ($nkj = 0; $nkj <= 9; $nkj++) {
                 $nkk = $nkBoard[$nki * 10 + $nkj];
                 if ($nkk != 100) {
                          if ($nkk == 0)
                               echo "--";
                          else if ($nkk > 0)
                               echo "+" . $nkk;
                          else
                               echo $nkk;
                          echo "|";
                 }
             }
             echo "<br>\n";
        }
}

# help function for creating notation

function get_pgn_piece($nkaPiece) {
        switch (Abs($nkaPiece)) {
               case WK: return "K";
               case WQ: return "Q";
               case WR: return "R";
               case WB: return "B";
               case WN: return "N";
               case WP: return "";
        }
        return "X";
}

# 0..63 to 21..98

function c0_21($nki) {
        return ($nki >> 3) * 10 + ((($nki + 8) % 8)) + 21;
}

# 21..98 to 0..63

function c21_0($nki) {
        return ((floor($nki / 10) - 2) << 3) + (($nki % 10) - 1);
}

# The following functions search the corresponding piece what can move to $nkfrom
# Used for checking whether a square is attacked

function search_Queen($nkfrom, $nkturn) {
         global $nkBoard, $nkab_Queen, $nkpgn_square_list;
         $nkretVal = 0;
         for ($nki = 0; $nki <= 7; $nki++) {
               $nkj = $nkfrom;
               while (TRUE) {
                     $nkj = $nkj + $nkab_Queen[$nki];
                     if ($nkBoard[$nkj] == 100)
                                   break;
                     if ($nkBoard[$nkj] == $nkturn * WQ) {
                                   $nkpgn_square_list[$nkretVal] = $nkj;
                                   $nkretVal++;
                     }
                     if ($nkBoard[$nkj] != 0)
                            break;
               }
         }
         return $nkretVal;
}

function search_Rook($nkfrom, $nkturn) {
         global $nkBoard, $nkab_Rook, $nkpgn_square_list;
         $nkretVal = 0;
         for ($nki = 0; $nki <= 3; $nki++) {
               $nkj = $nkfrom;
               while (TRUE) {
                     $nkj = $nkj + $nkab_Rook[$nki];
                     if ($nkBoard[$nkj] == 100)
                                   break;
                     if ($nkBoard[$nkj] == $nkturn * WR)  {
                                   $nkpgn_square_list[$nkretVal] = $nkj;
                                   $nkretVal++;
                     }
                     if ($nkBoard[$nkj] != 0)
                            break;
               }
         }
         return $nkretVal;
}

function search_Bishop($nkfrom, $nkturn) {
         global $nkBoard, $nkab_Bishop, $nkpgn_square_list;
         $nkretVal = 0;
         for ($nki = 0; $nki <= 3; $nki++) {
               $nkj = $nkfrom;
               while (TRUE) {
                     $nkj = $nkj + $nkab_Bishop[$nki];
                     if ($nkBoard[$nkj] == 100)
                                   break;
                     if ($nkBoard[$nkj] == $nkturn * WB)  {
                                   $nkpgn_square_list[$nkretVal] = $nkj;
                                   $nkretVal++;
                     }
                     if ($nkBoard[$nkj] != 0)
                            break;
               }
         }
         return $nkretVal;
}

function search_Knight($nkfrom, $nkturn) {
         global $nkBoard, $nkab_Knight, $nkpgn_square_list;
         $nkretVal = 0;
         for ($nki = 0; $nki <= 7; $nki++) {
               $nkj = $nkfrom;
               $nkj = $nkj + $nkab_Knight[$nki];
               if ($nkBoard[$nkj] == $nkturn * WN) {
                             $nkpgn_square_list[$nkretVal] = $nkj;
                             $nkretVal++;
               }
         }
         return $nkretVal;
}

function search_King($nkfrom, $nkturn) {
         global $nkBoard, $nkab_King, $nkpgn_square_list;
         $nkretVal = 0;
         for ($nki = 0; $nki <= 7; $nki++) {
               $nkj = $nkfrom;
               $nkj = $nkj + $nkab_King[$nki];
               if ($nkBoard[$nkj] == $nkturn * WK)  {
                             $nkpgn_square_list[$nkretVal] = $nkj;
                             $nkretVal++;
               }
         }
         return $nkretVal;
}


function search_capturePawn($nkfrom, $nkturn) {
    global $nkBoard, $nkpgn_square_list;
    $nkretVal = 0;
    if ($nkBoard[$nkfrom + (-$nkturn * 9 )] == $nkturn * WP)  {
             $nkpgn_square_list[$nkretVal] = $nkj;
             $nkretVal++;
    }
    if ($nkBoard[$nkfrom + (-$nkturn * 11)] == $nkturn * WP) {
             $nkpgn_square_list[$nkretVal] = $nkj;
             $nkretVal++;
    }
    return $nkretVal;
}

function search_Pawn($nkfrom, $nkturn) {
    global $nkBoard, $nkpgn_square_list;
    $nkretVal = 0;
    if ($nkBoard[$nkfrom + (-$nkturn * 10)] == $nkturn * WP) {
          $nkpgn_square_list[$nkretVal] = $nkj;
          $nkretVal++;
    }
    else if ($nkBoard[$nkfrom + (-$nkturn * 10)] == 0)
        if (
          (($nkturn == 1) && (($nkfrom > sq_h3) && ($nkfrom < sq_a5))) ||
          (($nkturn != 1) && (($nkfrom > sq_h4) && ($nkfrom < sq_a6)))
        )
             if ($nkBoard[$nkfrom + (-$nkturn * 20)] == $nkturn * WP) {
                         $nkpgn_square_list[$nkretVal] = $nkj;
                         $nkretVal++;
             }
    return $nkretVal;
}


# Check whether the king is attacked
# The turn is changed and it is looked for a opponent's piece what is able to reach this square

function attacked($nkfrom, $nkturn) {
      if (
        (search_King($nkfrom, -$nkturn) != 0)
        || (search_Queen($nkfrom, -$nkturn) != 0)
        || (search_Rook($nkfrom, -$nkturn) != 0)
        || (search_Bishop($nkfrom, -$nkturn) != 0)
        || (search_Knight($nkfrom, -$nkturn) != 0)
        || (search_CapturePawn($nkfrom, -$nkturn) != 0)
      )
              return TRUE;
      else
              return FALSE;
}


# A "free" square may not be a edge value (100) or a square where an own piece is placed

function is_Square_free($nkSquare, $nkturn) {
         global $nkBoard;
         if ($nkBoard[$nkSquare] == 100)
                     return FALSE;
         if (
            (($nkturn ==  1) && ($nkBoard[$nkSquare] > 0)) ||
            (($nkturn !=  1) && ($nkBoard[$nkSquare] < 0))
         )
                     return FALSE;
         return TRUE;
}


# Adds a move to the list

function Move_to_List($nkfrom, $nkto) {
         global $nkmove_list_count, $nkmove_list_to, $nkmove_list_from;
         $nkmove_list_from[$nkmove_list_count] = $nkfrom;
         $nkmove_list_to[$nkmove_list_count] = $nkto;
         $nkmove_list_count++;
}


# The following functions check the squares where a piece from a certain square can move to
# They are added to the move list (it must still be verified whether the move is legal)
# If a $nkto is a legal square (instead of 0), the return value is TRUE if the move list contains this square

function get_QueenSquares($nkfrom, $nkturn, $nkto) {
    global $nkBoard, $nkab_Queen;
    for ($nki = 0; $nki <= 7; $nki++) {
               $nkj = $nkfrom;
               while (TRUE) {
                     $nkj = $nkj + $nkab_Queen[$nki];
                     if (!is_Square_free($nkj, $nkturn))
                                   break;
                     Move_to_List($nkfrom, $nkj);
                     if ($nkj == $nkto)
                            return TRUE;
                     if ($nkBoard[$nkj] != 0)
                            break;
               }
         }
    return FALSE;
}

function get_RookSquares($nkfrom, $nkturn, $nkto) {
    global $nkBoard, $nkab_Rook;
    for ($nki = 0; $nki <= 3; $nki++) {
               $nkj = $nkfrom;
               while (TRUE) {
                     $nkj = $nkj + $nkab_Rook[$nki];
                     if (!is_Square_free($nkj, $nkturn))
                               break;
                     Move_to_List($nkfrom, $nkj);
                     if ($nkj == $nkto)
                            return TRUE;
                     if ($nkBoard[$nkj] != 0)
                            break;
               }
         }
    return FALSE;
}

function get_BishopSquares($nkfrom, $nkturn, $nkto) {
    global $nkBoard, $nkab_Bishop;
    for ($nki = 0; $nki <= 3; $nki++) {
               $nkj = $nkfrom;
               while (TRUE) {
                     $nkj = $nkj + $nkab_Bishop[$nki];
                     if (!is_Square_free($nkj, $nkturn))
                               break;
                     Move_to_List($nkfrom, $nkj);
                     if ($nkj == $nkto)
                            return TRUE;
                     if ($nkBoard[$nkj] != 0)
                            break;
               }
         }
    return FALSE;
}

function get_KnightSquares($nkfrom, $nkturn, $nkto) {
    global $nkab_Knight;
    for ($nki = 0; $nki <= 7; $nki++) {
        $nkj = $nkfrom;
        $nkj = $nkj + $nkab_Knight[$nki];
        if (is_Square_free($nkj, $nkturn)) {
           Move_to_List($nkfrom, $nkj);
           if ($nkj == $nkto)
              return TRUE;
        }
    }
    return FALSE;
}

function get_KingSquares($nkfrom, $nkturn, $nkto) {
    global $nkBoard, $nkab_King;
    global $nkmove_castling_ws, $nkmove_castling_wl, $nkmove_castling_bs, $nkmove_castling_bl;
    for ($nki = 0; $nki <= 7; $nki++) {
        $nkj = $nkfrom;
        $nkj = $nkj + $nkab_King[$nki];
        if (is_Square_free($nkj, $nkturn)) {
             Move_to_List($nkfrom, $nkj);
             if ($nkj == $nkto)
                    return TRUE;
        }
    }

# Additionally check castling possibilities
    if ($nkturn == 1) {
      if ($nkmove_castling_ws) {
        if  (
          (($nkBoard[sq_e1] == WK) && ($nkBoard[sq_h1] == WR))
          && (($nkBoard[sq_f1] == 0) && (!attacked(sq_f1, $nkturn)))
          && (($nkBoard[sq_g1] == 0) && (!attacked(sq_g1, $nkturn)))
          && (!attacked(sq_e1, $nkturn))
        ) {
             Move_to_List(sq_e1, sq_g1);
             if (sq_g1 == $nkto)
                   return TRUE;
        }
      }
      if ($nkmove_castling_wl) {
        if  (
          (($nkBoard[sq_e1] == WK) && ($nkBoard[sq_a1] == WR))
          && ($nkBoard[sq_b1] == 0)
          && (($nkBoard[sq_d1] == 0) && (!attacked(sq_d1, $nkturn)))
          && (($nkBoard[sq_c1] == 0) && (!attacked(sq_c1, $nkturn)))
          && (!attacked(sq_e1, $nkturn))
        ) {
            Move_to_List(sq_e1, sq_c1);
            if (sq_c1 == $nkto)
                  return TRUE;
        }
      }
    }
    else {
      if ($nkmove_castling_bs) {
        if (
          (($nkBoard[sq_e8] == BK) && ($nkBoard[sq_h8] == BR))
          && (($nkBoard[sq_f8] == 0) && (!attacked(sq_f8, $nkturn)))
          && (($nkBoard[sq_g8] == 0) && (!attacked(sq_g8, $nkturn)))
          && (!attacked(sq_e8, $nkturn))
        ) {
             Move_to_List(sq_e8, sq_g8);
             if (sq_g8 == $nkto)
                  return TRUE;
        }
      }
      if ($nkmove_castling_bl) {
        if (
          (($nkBoard[sq_e8] == BK) && ($nkBoard[sq_a8] == BR))
          && ($nkBoard[sq_b8] == 0)
          && (($nkBoard[sq_d8] == 0) && (!attacked(sq_d8, $nkturn)))
          && (($nkBoard[sq_c8] == 0) && (!attacked(sq_c8, $nkturn)))
          && (!attacked(sq_e8, $nkturn))
        ) {
              Move_to_List(sq_e8, sq_c8);
              if (sq_c8 == $nkto)
                  return TRUE;
        }
      }
    }
    return FALSE;
}

function get_PawnSquares($nkfrom, $nkturn, $nkto) {
    global $nkBoard, $nkmove_ep_Square;

# Check the square in front of the pawn
    if ($nkBoard[$nkfrom + ($nkturn * 10)] == 0) {
      Move_to_List($nkfrom, $nkfrom + ($nkturn * 10));
      if ($nkfrom + ($nkturn * 10) == $nkto)
                  return TRUE;

# If the pawn is located on the second rank, check the next square too
      if (
        (($nkturn == 1) && (($nkfrom > sq_h1) && ($nkfrom < sq_a3)))
        || (($nkturn <> 1) && (($nkfrom > sq_h6) && ($nkfrom < sq_a8)))
      )
        if ($nkBoard[$nkfrom + ($nkturn * 20)] == 0) {
           Move_to_List($nkfrom, $nkfrom + ($nkturn * 20));
           if ($nkfrom + ($nkturn * 20) == $nkto)
                  return TRUE;
        }
    }

# Check capture possibilities
    if ($nkturn == 1) {
      if (
        (($nkBoard[$nkfrom + ($nkturn * 9)] != 100) && ($nkBoard[$nkfrom + ($nkturn * 9)] < 0))
        || ($nkfrom + ($nkturn * 9) == $nkmove_ep_Square)
      ) {
          Move_to_List($nkfrom, $nkfrom + ($nkturn * 9));
          if ($nkfrom + ($nkturn * 9) == $nkto)
                  return TRUE;
      }
      if (
        (($nkBoard[$nkfrom + ($nkturn * 11)] != 100) && ($nkBoard[$nkfrom + ($nkturn * 11)] < 0))
        || ($nkfrom + ($nkturn * 11) == $nkmove_ep_Square)
      ) {
          Move_to_List($nkfrom, $nkfrom + ($nkturn * 11));
          if ($nkfrom + ($nkturn * 11) == $nkto)
                  return TRUE;
      }
    }
    else {
      if (
        (($nkBoard[$nkfrom + ($nkturn * 9)] != 100) && ($nkBoard[$nkfrom + ($nkturn * 9)] > 0))
        || ($nkfrom + ($nkturn * 9) == $nkmove_ep_Square)
      ) {
          Move_to_List($nkfrom, $nkfrom + ($nkturn * 9));
          if ($nkfrom + ($nkturn * 9) == $nkto)
                  return TRUE;
      }
      if (
        (($nkBoard[$nkfrom + ($nkturn * 11)] != 100) && ($nkBoard[$nkfrom + ($nkturn * 11)] > 0))
        || ($nkfrom + ($nkturn * 11) == $nkmove_ep_Square)
      ) {
          Move_to_List($nkfrom, $nkfrom + ($nkturn * 11));
          if ($nkfrom + ($nkturn * 11) == $nkto)
                  return TRUE;
      }
    }
    return FALSE;
}


# Returns the king's place

function get_King($nkwhite) {
    global $nkBoard;
    if ($nkwhite)
        $nkj = WK;
    else
        $nkj = BK;
    for ($nki = 0; $nki <= 119; $nki++) {
        if ($nkBoard[$nki] == $nkj)
             return $nki;
    }
    return -1;
}


# Checks whether a move is legal according to the set move variables

function is_Move_possible() {
      global $nkBoard, $nkmove_list_count, $nkmove_turn, $nkmove_ep_Square, $nkmove_to_Square;
      global $nkmove_from_Square, $nkpgn_piece, $nkpgn_from_digit, $nkpgn_from_letter, $nkpgn_capture, $nkpgn_square_list;
# Legal from square?
      $nkf = $nkBoard[$nkmove_from_Square];
      if (($nkf == 0) || ($nkf == 100))
           return FALSE;

# The right colored piece on it?
      if (
        (($nkmove_turn == 1) && ($nkf < 0)) ||
        (($nkmove_turn != 1) && ($nkf > 0))
      )
        return FALSE;
# Get the to squares of the corresponding piece
# The function returns TRUE if our to_square fits with one of them

      $nkf = Abs($nkf);
      $nkb = FALSE;
      $nkmove_list_count = 0;
      if ($nkf == WK)
          $nkb = get_KingSquares($nkmove_from_Square, $nkmove_turn, $nkmove_to_Square);
      else if ($nkf == WQ)
          $nkb = get_QueenSquares($nkmove_from_Square, $nkmove_turn, $nkmove_to_Square);
      else if ($nkf == WR)
          $nkb = get_RookSquares($nkmove_from_Square, $nkmove_turn, $nkmove_to_Square);
      else if ($nkf == WB)
          $nkb = get_BishopSquares($nkmove_from_Square, $nkmove_turn, $nkmove_to_Square);
      else if ($nkf == WN)
          $nkb = get_KnightSquares($nkmove_from_Square, $nkmove_turn, $nkmove_to_Square);
      else if ($nkf == WP)
          $nkb = get_PawnSquares($nkmove_from_Square, $nkmove_turn, $nkmove_to_Square);

# Set piece to the new square and check whether own king is attacked
      if ($nkb) {
            $nkrv_f  = $nkBoard[$nkmove_from_Square];
            $nkrn_f  = $nkBoard[$nkmove_to_Square];
            $nkrep_f = $nkBoard[$nkmove_to_Square + (-$nkmove_turn * 10)];

            $nkBoard[$nkmove_to_Square] = $nkBoard[$nkmove_from_Square];
            $nkBoard[$nkmove_from_Square] = 0;
            if (($nkf == WP) && ($nkmove_ep_Square == $nkmove_to_Square))
               $nkBoard[$nkmove_to_Square + (-$nkmove_turn * 10)] = 0;

            $nkRetVal = false;
            $nki = get_King($nkmove_turn == 1);
            if ($nki != -1)
               $nkRetVal = !attacked($nki, $nkmove_turn);

            $nkBoard[$nkmove_from_Square]                     = $nkrv_f;
            $nkBoard[$nkmove_to_Square]                       = $nkrn_f;
            $nkBoard[$nkmove_to_Square + (-$nkmove_turn * 10)]  = $nkrep_f;

            $nkpgn_piece = "";           // for adding a move to pgn notation
            $nkpgn_from_digit = "";
            $nkpgn_from_letter = "";
            $nkpgn_capture = FALSE;
            if ($nkRetVal) {
                 $nkpgn_piece = get_pgn_piece($nkBoard[$nkmove_from_Square]);
                 $nkpgn_capture =  ($nkBoard[$nkmove_to_Square] != 0) || (($nkf == WP) && ($nkmove_ep_Square == $nkmove_to_Square));
                 $nki = 1;
                 switch (Abs($nkBoard[$nkmove_from_Square])) {
                        case WQ:  $nki = search_Queen($nkmove_to_Square, $nkmove_turn);
                                  break;
                        case WR:  $nki = search_Rook($nkmove_to_Square, $nkmove_turn);
                                  break;
                        case WB:  $nki = search_Bishop($nkmove_to_Square, $nkmove_turn);
                                  break;
                        case WN:  $nki = search_Knight($nkmove_to_Square, $nkmove_turn);
                                  break;
                 }
                 if ($nki > 1) {
                      $nkhl = c21_0($nkmove_from_Square) % 8;
                      $nkhr = floor(c21_0($nkmove_from_Square) / 8);
                      for ($nkj = 0; $nkj < $nki; $nkj++) {
                            if ($nkmove_from_Square != $nkpgn_square_list[$nkj]) {
                                  $nkfile = c21_0($nkpgn_square_list[$nkj])  % 8;
                                  $nkrank = floor(c21_0($nkpgn_square_list[$nkj]) / 8);
                                  if ($nkhl == $nkfile)
                                          $nkpgn_from_digit = floor(c21_0($nkmove_from_Square) / 8) + 1;
                                  if ($nkhr == $nkrank)
                                          $nkpgn_from_letter = chr((c21_0($nkmove_from_Square) % 8) + 97);



                           }
                     }
                     # neither on the same file nor the same rank (knight)
                     if ($nkpgn_from_digit == "")
                           $nkpgn_from_letter = chr((c21_0($nkmove_from_Square) % 8) + 97);
                }

            }
            return $nkRetVal;
     }
     return FALSE;
}


# Execute a move according to the set move variables
# Sets ep-square and castling rights
# Changes the turn

function execute_Move() {
     global $nkBoard, $nkmove_turn, $nkmove_promotion_figur, $nkmove_ep_Square, $nkmove_to_Square, $nkmove_from_Square;
     global $nkmove_castling_ws, $nkmove_castling_wl, $nkmove_castling_bs, $nkmove_castling_bl, $nkpgn_castling, $nkmove_PlyNumber;

# Set from- and to-square

     $nkBoard[$nkmove_to_Square] = $nkBoard[$nkmove_from_Square];
     $nkPiece = Abs($nkBoard[$nkmove_from_Square]);
     $nkBoard[$nkmove_from_Square] = 0;

     $nkpgn_castling = "";

     $nkep = $nkmove_ep_Square;
     $nkmove_ep_Square = 0;
     if ($nkPiece == WP) {

# if to-square is ep-square, remove pawn above

        if ($nkep == $nkmove_to_Square)
            $nkBoard[$nkmove_to_Square + (-$nkmove_turn * 10)] = 0;

# if promotion, set new piece

        if ($nkmove_promotion_figur != 0)
             $nkBoard[$nkmove_to_Square] =  $nkmove_promotion_figur;

# set new ep_square if double step and an opponent's pawn is placed on the nearby square

        if ($nkmove_from_Square + ($nkmove_turn * 20) == $nkmove_to_Square) {
               $nkmove_ep_Square =  $nkmove_from_Square + ($nkmove_turn * 10);
        }
     }
     else if ($nkPiece == WK) {

# set rook and castling rights if necessary

          if ($nkmove_from_Square == sq_e1) {
                    if ($nkmove_to_Square == sq_g1) {
                             $nkBoard[sq_h1] = 0;
                             $nkBoard[sq_f1] = WR;
                             $nkpgn_castling = "O-O";
                    }
                    else if ($nkmove_to_Square == sq_c1) {
                             $nkBoard[sq_a1] = 0;
                             $nkBoard[sq_d1] = WR;
                             $nkpgn_castling = "O-O-O";
                    }
                    $nkmove_castling_ws = FALSE;
                    $nkmove_castling_wl = FALSE;
          }
          else if ($nkmove_from_Square == sq_e8) {
                    if ($nkmove_to_Square == sq_g8) {
                             $nkBoard[sq_h8] = 0;
                             $nkBoard[sq_f8] = BR;
                             $nkpgn_castling = "O-O";
                    }
                    else if ($nkmove_to_Square == sq_c8) {
                             $nkBoard[sq_a8] = 0;
                             $nkBoard[sq_d8] = BR;
                             $nkpgn_castling = "O-O-O";
                    }
                    $nkmove_castling_bs = FALSE;
                    $nkmove_castling_bl = FALSE;
          }

     }
     if (($nkmove_from_Square == sq_h1) || ($nkmove_to_Square == sq_h1))
          $nkmove_castling_ws = FALSE;
     if (($nkmove_from_Square == sq_a1) || ($nkmove_to_Square == sq_a1))
          $nkmove_castling_wl = FALSE;
     if (($nkmove_from_Square == sq_h8) || ($nkmove_to_Square == sq_h8))
          $nkmove_castling_bs = FALSE;
     if (($nkmove_from_Square == sq_a8) || ($nkmove_to_Square == sq_a8))
          $nkmove_castling_bl = FALSE;

     $nkmove_turn = -$nkmove_turn;
     $nkmove_PlyNumber++;
}


# Converts e4 to 55, for example
# If it cannot be converted, return 0 (an illegal square)

function get_Square($nkFeld) {
    if (strlen($nkFeld) != 2)
               return 0;
    $nkx = ord($nkFeld[0]) - 97;
    $nky = $nkFeld[1];
    if (($nkx < 0) || ($nkx > 7) || ($nky < 1) || ($nky > 8))
               return 0;
    $nkx = (($nky - 1) << 3) + $nkx;
    $nkx = ($nkx >> 3) * 10 + ((($nkx + 8) % 8)) + 21;
    if (($nkx < 21) || ($nkx > 98))
               return 0;
    return $nkx;
}


# Syntax must be "h7-h8Q", castling e1-g1

function check_MoveSyntax($nkMove) {
         if ((strlen($nkMove) < 5) || (strlen($nkMove) > 6))
                 return FALSE;
         if ($nkMove[2] != "-")
                 return FALSE;
         return TRUE;
}


# Resets the move variables

function reset_Move_Vars() {
  global $nkmove_turn, $nkmove_promotion_figur, $nkmove_ep_Square, $nkmove_to_Square, $nkmove_from_Square;
  global $nkmove_castling_ws, $nkmove_castling_wl, $nkmove_castling_bs, $nkmove_castling_bl, $nkmove_PlyNumber;
  $nkmove_from_Square = 0;
  $nkmove_to_Square = 0;
  $nkmove_ep_Square = 0;
  $nkmove_promotion_figur = 0;
  $nkmove_turn = 1;
  $nkmove_castling_ws = TRUE;
  $nkmove_castling_wl = TRUE;
  $nkmove_castling_bs = TRUE;
  $nkmove_castling_bl = TRUE;
  $nkmove_PlyNumber = 0;
}


# Extracts from- and to-square from a move (e2-e4, e1-g1, h7-h8Q)
# and sets the move variables
# Then it checks whether the move is legal (it does not execute the move)

function set_Move_Vars($nkaMove) {
    global $nkBoard, $nkmove_turn, $nkmove_promotion_figur, $nkmove_to_Square, $nkmove_from_Square;
    if (!check_MoveSyntax($nkaMove))
               return FALSE;
    $nkmove_from_Square = get_Square(substr($nkaMove, 0, 2));
    $nkmove_to_Square = get_Square(substr($nkaMove, 3, 2));
    $nkmove_promotion_figur = 0;

# Check whether promotion piece is defined
    if (
      (Abs($nkBoard[$nkmove_from_Square]) == WP) &&
      (($nkmove_to_Square > sq_h7) || ($nkmove_to_Square < sq_a2))
    )  {
           if (strlen($nkaMove) < 6)
                  $nks_promotion_figur = "Q";
           else
                  $nks_promotion_figur = substr($nkaMove, 5, 1);
           if ($nks_promotion_figur == "Q")
                  $nkmove_promotion_figur = $nkmove_turn * WQ;
           else if ($nks_promotion_figur == "R")
                  $nkmove_promotion_figur = $nkmove_turn * WR;
           else if ($nks_promotion_figur == "B")
                  $nkmove_promotion_figur = $nkmove_turn * WB;
           else if ($nks_promotion_figur == "N")
                  $nkmove_promotion_figur = $nkmove_turn * WN;
    }
    if (($nkmove_to_Square == 0) || ($nkmove_from_Square == 0) || (!is_Move_possible()))
        return FALSE;
    return TRUE;
}


# Counts all legal moves to check for mate and stalemate

function Move_Count() {
  global $nkBoard, $nkmove_list_count, $nkmove_list_to, $nkmove_turn, $nkmove_ep_Square;
  $nkRetVal = 0;
  $nkKing_Place = get_King($nkmove_turn == 1);
  if ($nkKing_Place != -1) {

# get the moves from all pieces on the board

    for ($nki = 0; $nki <= 63; $nki++) {
        $nkv = c0_21($nki);
        $nkf = $nkBoard[$nkv];
        if (
          (($nkf != 0) && ($nkf != 100))
          && (!(($nkmove_turn == 1) && ($nkf < 0)))
          && (!(($nkmove_turn != 1) && ($nkf > 0)))
        ) {
            $nkmove_list_count = 0;

            if (Abs($nkf) == WK)
                get_KingSquares($nkv, $nkmove_turn, 0);
            else if (Abs($nkf) == WQ)
                get_QueenSquares($nkv, $nkmove_turn, 0);
            else if (Abs($nkf) == WR)
                get_RookSquares($nkv, $nkmove_turn, 0);
            else if (Abs($nkf) == WB)
                get_BishopSquares($nkv, $nkmove_turn, 0);
            else if (Abs($nkf) == WN)
                get_KnightSquares($nkv, $nkmove_turn, 0);
            else if (Abs($nkf) == WP)
                get_PawnSquares($nkv, $nkmove_turn, 0);

            for ($nkk = 0; $nkk < $nkmove_list_count; $nkk++) {
                 $nkn = $nkmove_list_to[$nkk];

# execute move on board after saving the old values
# do not forget ep, second part of castling is not necessary (only check for check)

                 $nkrep   = $nkn + (-$nkmove_turn * 10);
                 $nkrep_f = $nkBoard[$nkn + (-$nkmove_turn * 10)];
                 $nkrn_f  = $nkBoard[$nkn];
                 $nkrv_f  = $nkBoard[$nkv];

                 $nkBoard[$nkn] = $nkBoard[$nkv];
                 $nkBoard[$nkv] = 0;
                 if ((Abs($nkf) == WP) && ($nkmove_ep_Square == $nkn))
                       $nkBoard[$nkn + (-$nkmove_turn * 10)] = 0;

# king in check? If not, add to legal moves

                 if (Abs($nkf) == WK)
                         $nkw = $nkn;
                 else
                         $nkw = $nkKing_Place;
                 if (!attacked($nkw, $nkmove_turn)) {
                         $nkRetVal++;
                         if (
                           (Abs($nkf) == WP) &&
                           (($nkn < sq_a2) || ($nkn > sq_h7))
                         )
                         # Promotion +3
                                $nkRetVal = $nkRetVal + 3;
                 }

# Restore board for next loop

                 $nkBoard[$nkn]   = $nkrn_f;
                 $nkBoard[$nkv]   = $nkrv_f;
                 $nkBoard[$nkrep] = $nkrep_f;
            }
        }
    }
  }
  return $nkRetVal;
}

# Returns a value depended on mate, stalemate, check and nothing of all
//# The "view point" is the own side after execution a move - the opponent

function get_GameState() {
   global $nkmove_turn;

# Running
  $nkRetVal = 0;
  $nkc = Move_Count();
  if ($nkc == 0) {
# Mate
        $nkRetVal = 1;
        if (!attacked(get_King($nkmove_turn == 1), $nkmove_turn))
# Stalemate
                  $nkRetVal = 2;
  }
  else
        if (attacked(get_King($nkmove_turn == 1), $nkmove_turn))
# Check
                  $nkRetVal = 3;
  return $nkRetVal;
}

function State_to_String($nki) {
        switch ($nki) {
                case gsMate      : return "Mate";
                case gsStalemate : return "Stalemate";
                case gsCheck     : return "Check";
                default          : return "";
        }
}

# Sets up the first position and resets the move variables

function set_first_Position() {
  global $nkBoard, $nkfirst_Position, $nkNotation;
  $nkNotation = "";
  for ($nki = 0; $nki <= 119; $nki++)
       $nkBoard[$nki] = $nkfirst_Position[$nki];
  reset_Move_Vars();
}

# Reads a game an sets up the last (current) position
# $nkMoves are delivered as sql result

function read_Game($nkMoves) {
    global $nkNotation;
    set_first_Position();
    $nkl = 0;
    while ($nkrow = mysql_fetch_array ($nkMoves)) {
        $nkl++;
        if (!add_Move($nkrow["Move"]))
               return FALSE;
        if ($nkl > 7) {
               $nkNotation = $nkNotation . "\n";
               $nkl = 0;
        }
    }
    return TRUE;
}


# Checks the syntax of move (e2-e4), initiate the variables and execute it if possible

function add_Move($nkMove) {
        global $nkNotation, $nkState, $nkpgn_piece, $nkpgn_from_letter, $nkpgn_from_digit, $nkpgn_capture;
        global $nkmove_promotion_figur, $nkpgn_castling, $pgn_Move, $nkmove_PlyNumber;
        global $simplemove;
        if (!set_Move_Vars($nkMove))
               return FALSE;
        execute_Move();

# Create pgn notation
        $nkMoveNumber = "";
        if ($nkmove_PlyNumber % 2) {
               $nkMoveNumber = (floor($nkmove_PlyNumber / 2) + 1) . ".";
               $nkMoveNumber1 = $nkMoveNumber;
        }
        else
               $nkMoveNumber1 = (floor(($nkmove_PlyNumber - 1) / 2) + 1) . ". ... ";

        if ($nkpgn_castling == "") { // This is set in execute_Move() unlike all other "pgn_" values which are set in is_Move_Possible()
          $pgn_Move = substr($nkMove, 3, 2);    // a promotion letter is cut  --> add it below with =
          if ($nkpgn_capture) {
                 $nkcapture = "x";
                 if ($nkpgn_piece == "")   // Pawn
                       $nkpgn_piece = substr($nkMove, 0, 1);
          }
          else
                 $nkcapture = "";
          if ($nkmove_promotion_figur != 0)
                 $pgn_Move = $pgn_Move . "=" . get_pgn_piece($nkmove_promotion_figur);
          $pgn_Move = $nkpgn_piece . $nkpgn_from_letter . $nkpgn_from_digit . $nkcapture . $pgn_Move;
        }
        else
          $pgn_Move = $nkpgn_castling;

        $nkState = get_GameState();
        if ($nkState == 3)
               $pgn_Move = $pgn_Move . "+";
        else if ($nkState == 1)
               $pgn_Move = $pgn_Move . "#";

		$simplemove=$pgn_Move;
        $nkNotation = $nkNotation . $nkMoveNumber . $pgn_Move . " ";

        $pgn_Move = $nkMoveNumber1 . $pgn_Move;

        return TRUE;
}

# Delivers html. The gif files must be located in /images

function do_get_current_Position($nkMoves) {
        if (!read_Game($nkMoves))
              return "";
        return get_current_Position();
}

function get_current_Position() {
        global $nkBoard;

        $nkfa  = "<font COLOR=#000000 SIZE=-1 FACE='MS Sans Serif'>";
        $nkfe  = "</font>";
        $nkdc  = "#D5D5D5";
        $nkk   = "abcdefgh";
        $nkds  = "#F8E1B8";
	$nkdz  = "";
	$nkdsq = "";

        $nks = "<table BORDER=3><tbody><tr><td><table BORDER=0 CELLPADDING=0 CELLSPACING=0><tbody>";
# Coordinates
	$nks = $nks . "<tr><td BGCOLOR=" . $nkdc . ">&nbsp;</td>";
	for ($nki = 0; $nki < 8; $nki++) {
		$nks = $nks . "<td BGCOLOR=" . $nkdc . " align=middle>&nbsp;" . $nkfa . substr($nkk, $nki, 1) . $nkfe . "&nbsp;</TD>";
        }
	$nks = $nks . "<td BGCOLOR=" . $nkdc . ">&nbsp;</td></tr>";
#
        for ($nki = 0; $nki < 8; $nki++) {
		$nks = $nks . "<TR>";
                $nks = $nks . "<td BGCOLOR=" . $nkdc . " align=middle>&nbsp;" . $nkfa . Abs($nki - 8) . $nkfe . "&nbsp;</td>";
		if ($nkds == "#F8E1B8") {
                     $nkdsq = "";
                     $nkds = "#AE823E";
                }
		else {
                     $nkdsq = "";
                     $nkds = "#F8E1B8";
                }
		for ($nkj = 0; $nkj < 8; $nkj++) {
			if ($nkds == "#F8E1B8") {
                               $nkdsq = "";
                               $nkds = "#AE823E";
                        }
			else {
                               $nkdsq = "";
                               $nkds = "#F8E1B8";
                        }
			if ($nkdsq != "")
                               $nkdz = "<td BACKGROUND=" . $nkdsq . " BGCOLOR=" . $nkds . " >";
			else
                               $nkdz = "<td BGCOLOR=" . $nkds . ">";
		   	$nkdz = $nkdz . "<a href='javascript:lf(" . $nki . " * 8 + " . $nkj . ")'><img border=0 ";

# /images is path to pictures of pieces
                        $nkx = Abs($nkj - 7);
                        $nkx = ($nki << 3) + $nkx;
                        $nkx = Abs($nkx - 63);
                        $nkx = ($nkx >> 3) * 10 + ((($nkx + 8) % 8)) + 21;
                        if      ($nkBoard[$nkx] == WK) $nksi = "fwk33.gif";
                        else if ($nkBoard[$nkx] == WQ) $nksi = "fwd33.gif";
                        else if ($nkBoard[$nkx] == WR) $nksi = "fwt33.gif";
                        else if ($nkBoard[$nkx] == WB) $nksi = "fwl33.gif";
                        else if ($nkBoard[$nkx] == WN) $nksi = "fws33.gif";
                        else if ($nkBoard[$nkx] == WP) $nksi = "fwb33.gif";
                        else if ($nkBoard[$nkx] == BK) $nksi = "fsk33.gif";
                        else if ($nkBoard[$nkx] == BQ) $nksi = "fsd33.gif";
                        else if ($nkBoard[$nkx] == BR) $nksi = "fst33.gif";
                        else if ($nkBoard[$nkx] == BB) $nksi = "fsl33.gif";
                        else if ($nkBoard[$nkx] == BN) $nksi = "fss33.gif";
                        else if ($nkBoard[$nkx] == BP) $nksi = "fsb33.gif";
                        else                       $nksi = "fleer.gif";
			$nkdz = $nkdz . "src='images/" . $nksi . "' HEIGHT=33 WIDTH=33></a></TD>";
			$nks = $nks . $nkdz;
		}
                $nks = $nks . "<td BGCOLOR=" . $nkdc . " align=middle>&nbsp;" . $nkfa . Abs($nki - 8) . $nkfe . "&nbsp;</td>";
		$nks = $nks . "</TR>";
	}

# Coordinates
	$nks = $nks . "<tr><td BGCOLOR=" . $nkdc . ">&nbsp;</td>";
	for ($nki = 0; $nki < 8; $nki++) {
		$nks = $nks . "<td BGCOLOR=" . $nkdc . " align=middle>&nbsp;" . $nkfa . substr($nkk, $nki, 1) . $nkfe . "&nbsp;</TD>";
        }
	$nks = $nks . "<td BGCOLOR=" . $nkdc . ">&nbsp;</td></tr>";
#
        $nks = $nks . "</tbody></table></td></tr></tbody></table>";

        return $nks;
}

# FEN (for instance "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1" to $nkboard

function set_FEN($nkFEN) {
        global $nkBoard, $nkempty_Position, $nkNotation,
        $nkmove_ep_Square, $nkmove_turn, $nkmove_PlyNumber,
        $nkmove_castling_ws, $nkmove_castling_wl, $nkmove_castling_bs, $nkmove_castling_bl;

        for ($nki = 0; $nki <= 119; $nki++)
          $nkBoard[$nki] = $nkempty_Position[$nki];
        reset_Move_Vars();
        $nkNotation = "";

        $nki = 0;
        $nkk = 56;
        $nkidx = 0;
        while ($nkidx < strlen($nkFEN)) {
                $nkj = c0_21($nki + $nkk);
                $nkc = substr($nkFEN, $nkidx, 1);
                switch ($nkc) {
                        case "K": $nkBoard[$nkj] = WK; break;
                        case "Q": $nkBoard[$nkj] = WQ; break;
                        case "R": $nkBoard[$nkj] = WR; break;
                        case "B": $nkBoard[$nkj] = WB; break;
                        case "N": $nkBoard[$nkj] = WN; break;
                        case "P": $nkBoard[$nkj] = WP; break;
                        case "k": $nkBoard[$nkj] = BK; break;
                        case "q": $nkBoard[$nkj] = BQ; break;
                        case "r": $nkBoard[$nkj] = BR; break;
                        case "b": $nkBoard[$nkj] = BB; break;
                        case "n": $nkBoard[$nkj] = BN; break;
                        case "p": $nkBoard[$nkj] = BP; break;

                        case "1": $nki = $nki + 0; break;
                        case "2": $nki = $nki + 1; break;
                        case "3": $nki = $nki + 2; break;
                        case "4": $nki = $nki + 3; break;
                        case "5": $nki = $nki + 4; break;
                        case "6": $nki = $nki + 5; break;
                        case "7": $nki = $nki + 6; break;
                        case "8": $nki = $nki + 7; break;
                        case "/": $nki = -1; $nkk = $nkk - 8; break;
                        case "_": $nki = -1; $nkk = $nkk - 8; break;
                        case " ": $nkidx++;
                                  if (substr($nkFEN, $nkidx, 1) == "b")
                                        $nkmove_turn = -1;

                                  $nkidx = $nkidx + 2;
                                  $nkCastling = "";
                                  while ($nkidx < strlen($nkFEN)) {
                                        $nkc = substr($nkFEN, $nkidx, 1);
                                        if ($nkc == " ")
                                                break;
                                        $nkCastling = $nkCastling . $nkc;
                                        $nkidx++;
                                  }

                                  $nkmove_castling_ws = strstr($nkCastling, 'K');
                                  $nkmove_castling_wl = strstr($nkCastling, 'Q');
                                  $nkmove_castling_bs = strstr($nkCastling, 'k');
                                  $nkmove_castling_bl = strstr($nkCastling, 'q');

                                  $nkidx++;
                                  $nkep = "";
                                  while ($nkidx < strlen($nkFEN)) {
                                        $nkc = substr($nkFEN, $nkidx, 1);
                                        if ($nkc == " ")
                                                break;
                                        $nkep = $nkep . $nkc;
                                        $nkidx++;
                                  }
                                  $nkmove_ep_Square = get_Square($nkep);

                                  $nknb = "";
                                  $nkidx = strlen($nkFEN);
                                  while ($nkidx > 0) {
                                        $nkc = substr($nkFEN, $nkidx, 1);
                                        if ($nkc == " ")
                                                break;
                                        $nknb = $nkc . $nknb;
                                        $nkidx--;
                                  }
                                  if ($nknb != "") {
                                        $nknb = ($nknb - 1) * 2;
                                        if ($nkmove_turn == -1)
                                                $nknb++;
                                        $nkmove_PlyNumber = $nknb;
                                  }

                                  return TRUE;
                }
                $nki++;
                $nkidx++;
        }
        return FALSE;
}

function get_FEN() {
        global $nkBoard,
        $nkmove_ep_Square, $nkmove_turn, $nkmove_PlyNumber,
        $nkmove_castling_ws, $nkmove_castling_wl, $nkmove_castling_bs, $nkmove_castling_bl;

        $nks = "";
        $nki = 56;
        while ($nki > -1) {
                $nkj = 0;
                $nkl = 0;
                $nkf = "";
                while ($nkj < 8) {
                        $nkk = c0_21($nki + $nkj);

                        switch ($nkBoard[$nkk]) {
                                case WK: $nkf = "K"; break;
                                case WQ: $nkf = "Q"; break;
                                case WR: $nkf = "R"; break;
                                case WB: $nkf = "B"; break;
                                case WN: $nkf = "N"; break;
                                case WP: $nkf = "P"; break;
                                case BK: $nkf = "k"; break;
                                case BQ: $nkf = "q"; break;
                                case BR: $nkf = "r"; break;
                                case BB: $nkf = "b"; break;
                                case BN: $nkf = "n"; break;
                                case BP: $nkf = "p"; break;

                                default: $nkl++;
                        }
                        if (($nkf != "") || ($nkj == 7)) {
                                if ($nkl > 0) {
                                        $nks = $nks . $nkl;
                                        $nkl = 0;
                                }
                                $nks = $nks . $nkf;
                                $nkf = "";
                        }
                        $nkj++;
                }
                $nki = $nki - 8;
                if ($nki > -1)
                        $nks = $nks . "/";
        }
        if ($nkmove_turn == 1)
                $nks = $nks . " w ";
        else
                $nks = $nks . " b ";

        $nkr = "";
        if ($nkmove_castling_ws) $nkr = $nkr . "K";
        if ($nkmove_castling_wl) $nkr = $nkr . "Q";
        if ($nkmove_castling_bs) $nkr = $nkr . "k";
        if ($nkmove_castling_bl) $nkr = $nkr . "q";
        if ($nkr == "")
                $nkr = "-";
        $nks = $nks . $nkr;

        if ($nkmove_ep_Square > 0) {
                $nks = $nks . " " . chr((c21_0($nkmove_ep_Square) % 8) + 97);
                $nki = floor(c21_0($nkmove_ep_Square) / 8) + 1;
                $nks = $nks . $nki . " 0 ";
        }
        else
                $nks = $nks . " - 0 ";

        $nki = $nkmove_PlyNumber;
        if ($nkmove_turn == -1)
                $nki--;
        $nki = floor($nki / 2) + 1;

        return $nks . $nki;
}

function is_Move_legal($nkFEN, $nkMove) {
        set_FEN($nkFEN);
        if (!set_Move_Vars($nkMove))
               return FALSE;
        return TRUE;
}

function getResult()
{
	switch (get_GameState())
	{
		case gsMate:
			if ($move_PlayNumber % 2)
			{
				return "0-1";
			}
			else
			{
				return "1-0";
			}
		case gsStalemate: return "1/2-1/2";
		default: return "*";
	}
	return "?";
}
?>