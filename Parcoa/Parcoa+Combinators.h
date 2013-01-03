/*
   ____
  |  _ \ __ _ _ __ ___ ___   __ _   Parcoa - Objective-C Parser Combinators
  | |_) / _` | '__/ __/ _ \ / _` |
  |  __/ (_| | | | (_| (_) | (_| |  Copyright (c) 2012 James Brotchie
  |_|   \__,_|_|  \___\___/ \__,_|  https://github.com/brotchie/Parcoa


  The MIT License
  
  Copyright (c) 2012 James Brotchie
    - brotchie@gmail.com
    - @brotchie
  
  Permission is hereby granted, free of charge, to any person obtaining
  a copy of this software and associated documentation files (the
  "Software"), to deal in the Software without restriction, including
  without limitation the rights to use, copy, modify, merge, publish,
  distribute, sublicense, and/or sell copies of the Software, and to
  permit persons to whom the Software is furnished to do so, subject to
  the following conditions:
  
  The above copyright notice and this permission notice shall be
  included in all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
  LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
  OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
  WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#import "Parcoa+Internal.h"
#import "ParcoaParser.h"

typedef id (^ParcoaValueTransform)(id value);

@interface Parcoa (Combinators)

/** @name Combining Parsers with Combinators */

/** Returns the value of the first parser to
 *  match in an array. */
+ (ParcoaParser *)choice:(NSArray *)parsers;

/** Matches a parser n times. */
+ (ParcoaParser *)count:(ParcoaParser *)parser n:(NSUInteger)n;

/** If parser fails then return default value, otherwise return
 *  parser's value. */
+ (ParcoaParser *)option:(ParcoaParser *)parser default:(id)value;

/** If parser fails then return [NSNull null], otherwise return
 *  parser's value. */
+ (ParcoaParser *)optional:(ParcoaParser *)parser;

/** Only matches if parser matches and mustFail fails. mustFail will
 *  not consume output. Returns the value of parser. */
+ (ParcoaParser *)parser:(ParcoaParser *)parser notFollowedBy:(ParcoaParser *)following;

/** Matches a parser zero or more times returning an
 *  array of the values returned by children. */
+ (ParcoaParser *)many:(ParcoaParser *)parser;

/** Matches a parser one or more times returning an
 *  array of the values returned by children. */
+ (ParcoaParser *)many1:(ParcoaParser *)parser;

/** Matches a parser zero or more times separated
 *  by a delimiter parser. */
+ (ParcoaParser *)sepBy:(ParcoaParser *)parser delimiter:(ParcoaParser *)delimiter;

/** Matches a parser one or more times separated
 *  by a delimiter parser. */
+ (ParcoaParser *)sepBy1:(ParcoaParser *)parser delimiter:(ParcoaParser *)delimiter;

/** Matches an array of parsers in order. If all parsers
 *  match OK then the result value is an array
 *  containing all of the individual parser's values. */
+ (ParcoaParser *)sequential:(NSArray *)parsers;

/** Matches both parsers and return the left parser's value. */
+ (ParcoaParser *)keepLeft:(ParcoaParser *)left right:(ParcoaParser *)right;

/** Matches both parsers and return the right parser's value. */
+ (ParcoaParser *)keepRight:(ParcoaParser *)left right:(ParcoaParser *)right;

/** Matches parser sandwiched between a left and right parser.
 *  If all parsers match then the central value is returned. */
+ (ParcoaParser *)between:(ParcoaParser *)left parser:(ParcoaParser *)parser right:(ParcoaParser *)right;

/** If the wrapped parser matches OK then the result value is
 *  transformed by the transform block. This operation
 *  is equivalent to bind on the ParcoaParser * Monad. */
+ (ParcoaParser *)parser:(ParcoaParser *)parser transform:(ParcoaValueTransform)transform name:(NSString *)name;

/** Concatenates the array of strings returns by the parser
 *  into a single string. */
+ (ParcoaParser *)concat:(ParcoaParser *)parser;

/** Many followed by concat in a single combinator. */
+ (ParcoaParser *)concatMany:(ParcoaParser *)parser;

/** Many1 followed by concat in a single combinator. */
+ (ParcoaParser *)concatMany1:(ParcoaParser *)parser;

/** Matches the parser, skipping any whitespace before of after. */
+ (ParcoaParser *)skipSurroundingSpaces:(ParcoaParser *)parser;

+ (ParcoaParser *)parser:(ParcoaParser *)parser valueAtIndex:(NSUInteger)index;
@end
