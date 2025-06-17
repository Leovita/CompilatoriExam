// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 31 "parser.yy"

# include "driver.hpp"
YY_DECL;

#line 51 "parser.cpp"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (false)
# endif


// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 143 "parser.cpp"

  /// Build a parser object.
  parser::parser (driver& drv_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      drv (drv_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state), YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.YY_MOVE_OR_COPY< DefAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
        value.YY_MOVE_OR_COPY< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.YY_MOVE_OR_COPY< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.YY_MOVE_OR_COPY< IfExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.YY_MOVE_OR_COPY< LetExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.YY_MOVE_OR_COPY< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
        value.YY_MOVE_OR_COPY< std::pair<ExprAST*, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binding: // binding
        value.YY_MOVE_OR_COPY< std::pair<std::string, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param: // param
        value.YY_MOVE_OR_COPY< std::pair<std::string,ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deflist: // deflist
        value.YY_MOVE_OR_COPY< std::vector<DefAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.YY_MOVE_OR_COPY< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pairs: // pairs
        value.YY_MOVE_OR_COPY< std::vector<std::pair<ExprAST*, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bindings: // bindings
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params: // params
        value.YY_MOVE_OR_COPY< std::vector<std::pair<std::string,ExprAST*>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s, YY_MOVE (that.location))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.move< DefAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
        value.move< ExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.move< FunctionAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.move< IfExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.move< LetExprAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.move< PrototypeAST* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pair: // pair
        value.move< std::pair<ExprAST*, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_binding: // binding
        value.move< std::pair<std::string, ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_param: // param
        value.move< std::pair<std::string,ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_deflist: // deflist
        value.move< std::vector<DefAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_pairs: // pairs
        value.move< std::vector<std::pair<ExprAST*, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bindings: // bindings
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_params: // params
        value.move< std::vector<std::pair<std::string,ExprAST*>> > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.copy< DefAST* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
        value.copy< ExprAST* > (that.value);
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.copy< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.copy< IfExprAST* > (that.value);
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.copy< LetExprAST* > (that.value);
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.copy< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_pair: // pair
        value.copy< std::pair<ExprAST*, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_binding: // binding
        value.copy< std::pair<std::string, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_param: // param
        value.copy< std::pair<std::string,ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_deflist: // deflist
        value.copy< std::vector<DefAST*> > (that.value);
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.copy< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_pairs: // pairs
        value.copy< std::vector<std::pair<ExprAST*, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_bindings: // bindings
        value.copy< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_params: // params
        value.copy< std::vector<std::pair<std::string,ExprAST*>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_def: // def
        value.move< DefAST* > (that.value);
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
        value.move< ExprAST* > (that.value);
        break;

      case symbol_kind::S_funcdef: // funcdef
        value.move< FunctionAST* > (that.value);
        break;

      case symbol_kind::S_condexpr: // condexpr
        value.move< IfExprAST* > (that.value);
        break;

      case symbol_kind::S_letexpr: // letexpr
        value.move< LetExprAST* > (that.value);
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        value.move< PrototypeAST* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // "number"
        value.move< int > (that.value);
        break;

      case symbol_kind::S_pair: // pair
        value.move< std::pair<ExprAST*, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_binding: // binding
        value.move< std::pair<std::string, ExprAST*> > (that.value);
        break;

      case symbol_kind::S_param: // param
        value.move< std::pair<std::string,ExprAST*> > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_deflist: // deflist
        value.move< std::vector<DefAST*> > (that.value);
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        value.move< std::vector<ExprAST*> > (that.value);
        break;

      case symbol_kind::S_pairs: // pairs
        value.move< std::vector<std::pair<ExprAST*, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_bindings: // bindings
        value.move< std::vector<std::pair<std::string, ExprAST*>> > (that.value);
        break;

      case symbol_kind::S_params: // params
        value.move< std::vector<std::pair<std::string,ExprAST*>> > (that.value);
        break;

      default:
        break;
    }

    location = that.location;
    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " ("
            << yysym.location << ": ";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (drv));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_def: // def
        yylhs.value.emplace< DefAST* > ();
        break;

      case symbol_kind::S_expr: // expr
      case symbol_kind::S_boolexpr: // boolexpr
      case symbol_kind::S_literal: // literal
      case symbol_kind::S_relexpr: // relexpr
        yylhs.value.emplace< ExprAST* > ();
        break;

      case symbol_kind::S_funcdef: // funcdef
        yylhs.value.emplace< FunctionAST* > ();
        break;

      case symbol_kind::S_condexpr: // condexpr
        yylhs.value.emplace< IfExprAST* > ();
        break;

      case symbol_kind::S_letexpr: // letexpr
        yylhs.value.emplace< LetExprAST* > ();
        break;

      case symbol_kind::S_extdef: // extdef
      case symbol_kind::S_prototype: // prototype
        yylhs.value.emplace< PrototypeAST* > ();
        break;

      case symbol_kind::S_NUMBER: // "number"
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_pair: // pair
        yylhs.value.emplace< std::pair<ExprAST*, ExprAST*> > ();
        break;

      case symbol_kind::S_binding: // binding
        yylhs.value.emplace< std::pair<std::string, ExprAST*> > ();
        break;

      case symbol_kind::S_param: // param
        yylhs.value.emplace< std::pair<std::string,ExprAST*> > ();
        break;

      case symbol_kind::S_IDENTIFIER: // "id"
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_deflist: // deflist
        yylhs.value.emplace< std::vector<DefAST*> > ();
        break;

      case symbol_kind::S_arglist: // arglist
      case symbol_kind::S_args: // args
        yylhs.value.emplace< std::vector<ExprAST*> > ();
        break;

      case symbol_kind::S_pairs: // pairs
        yylhs.value.emplace< std::vector<std::pair<ExprAST*, ExprAST*>> > ();
        break;

      case symbol_kind::S_bindings: // bindings
        yylhs.value.emplace< std::vector<std::pair<std::string, ExprAST*>> > ();
        break;

      case symbol_kind::S_params: // params
        yylhs.value.emplace< std::vector<std::pair<std::string,ExprAST*>> > ();
        break;

      default:
        break;
    }


      // Default location.
      {
        stack_type::slice range (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, range, yylen);
        yyerror_range[1].location = yylhs.location;
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // startsymb: deflist
#line 98 "parser.yy"
                        { drv.root = yystack_[0].value.as < std::vector<DefAST*> > ();}
#line 882 "parser.cpp"
    break;

  case 3: // deflist: def deflist
#line 101 "parser.yy"
                        { yystack_[0].value.as < std::vector<DefAST*> > ().insert(yystack_[0].value.as < std::vector<DefAST*> > ().begin(),yystack_[1].value.as < DefAST* > ()); yylhs.value.as < std::vector<DefAST*> > () = yystack_[0].value.as < std::vector<DefAST*> > (); }
#line 888 "parser.cpp"
    break;

  case 4: // deflist: def
#line 102 "parser.yy"
                        { std::vector<DefAST*> D = {yystack_[0].value.as < DefAST* > ()}; yylhs.value.as < std::vector<DefAST*> > () = D; }
#line 894 "parser.cpp"
    break;

  case 5: // def: extdef
#line 105 "parser.yy"
                        { yylhs.value.as < DefAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 900 "parser.cpp"
    break;

  case 6: // def: funcdef
#line 106 "parser.yy"
                        { yylhs.value.as < DefAST* > () = yystack_[0].value.as < FunctionAST* > (); }
#line 906 "parser.cpp"
    break;

  case 7: // extdef: "external" prototype
#line 109 "parser.yy"
                        { yystack_[0].value.as < PrototypeAST* > ()->setext(); yylhs.value.as < PrototypeAST* > () = yystack_[0].value.as < PrototypeAST* > (); }
#line 912 "parser.cpp"
    break;

  case 8: // funcdef: "function" prototype expr "end"
#line 112 "parser.yy"
                                   { yylhs.value.as < FunctionAST* > () = new FunctionAST(yystack_[2].value.as < PrototypeAST* > (),yystack_[1].value.as < ExprAST* > ()); }
#line 918 "parser.cpp"
    break;

  case 9: // prototype: "id" "(" params ")"
#line 115 "parser.yy"
                        { yylhs.value.as < PrototypeAST* > () = new PrototypeAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<std::pair<std::string,ExprAST*>> > ()); }
#line 924 "parser.cpp"
    break;

  case 10: // params: %empty
#line 118 "parser.yy"
                        { std::vector<std::pair<std::string,ExprAST*>> params; yylhs.value.as < std::vector<std::pair<std::string,ExprAST*>> > () = params; }
#line 930 "parser.cpp"
    break;

  case 11: // params: param params
#line 119 "parser.yy"
                        { yystack_[0].value.as < std::vector<std::pair<std::string,ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<std::string,ExprAST*>> > ().begin(),yystack_[1].value.as < std::pair<std::string,ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<std::string,ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<std::string,ExprAST*>> > (); }
#line 936 "parser.cpp"
    break;

  case 12: // param: "id"
#line 122 "parser.yy"
                        { std::pair<std::string,ExprAST*> p(yystack_[0].value.as < std::string > (),nullptr); yylhs.value.as < std::pair<std::string,ExprAST*> > () = p; }
#line 942 "parser.cpp"
    break;

  case 13: // param: "id" "=" expr
#line 123 "parser.yy"
                       { std::pair<std::string,ExprAST*> p(yystack_[2].value.as < std::string > (),yystack_[0].value.as < ExprAST* > ()); yylhs.value.as < std::pair<std::string,ExprAST*> > () = p; }
#line 948 "parser.cpp"
    break;

  case 14: // expr: expr "+" expr
#line 134 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("+",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 954 "parser.cpp"
    break;

  case 15: // expr: expr "-" expr
#line 135 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("-",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 960 "parser.cpp"
    break;

  case 16: // expr: expr "*" expr
#line 136 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("*",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 966 "parser.cpp"
    break;

  case 17: // expr: expr "/" expr
#line 137 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("/",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 972 "parser.cpp"
    break;

  case 18: // expr: expr "%" expr
#line 138 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new BinaryExprAST("%",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 978 "parser.cpp"
    break;

  case 19: // expr: "-" expr
#line 139 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new UnaryExprAST("-",yystack_[0].value.as < ExprAST* > ()); }
#line 984 "parser.cpp"
    break;

  case 20: // expr: "(" expr ")"
#line 140 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = yystack_[1].value.as < ExprAST* > (); }
#line 990 "parser.cpp"
    break;

  case 21: // expr: "id"
#line 141 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new IdeExprAST(yystack_[0].value.as < std::string > ()); }
#line 996 "parser.cpp"
    break;

  case 22: // expr: "id" "(" arglist ")"
#line 142 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new CallExprAST(yystack_[3].value.as < std::string > (),yystack_[1].value.as < std::vector<ExprAST*> > ()); }
#line 1002 "parser.cpp"
    break;

  case 23: // expr: "number"
#line 143 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = new NumberExprAST(yystack_[0].value.as < int > ()); }
#line 1008 "parser.cpp"
    break;

  case 24: // expr: condexpr
#line 144 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < IfExprAST* > (); }
#line 1014 "parser.cpp"
    break;

  case 25: // expr: letexpr
#line 145 "parser.yy"
                         { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < LetExprAST* > (); }
#line 1020 "parser.cpp"
    break;

  case 26: // arglist: %empty
#line 148 "parser.yy"
                         { std::vector<ExprAST*> args; yylhs.value.as < std::vector<ExprAST*> > () = args; }
#line 1026 "parser.cpp"
    break;

  case 27: // arglist: args
#line 149 "parser.yy"
                         { yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1032 "parser.cpp"
    break;

  case 28: // args: expr
#line 152 "parser.yy"
                         { std::vector<ExprAST*> V = {yystack_[0].value.as < ExprAST* > ()}; yylhs.value.as < std::vector<ExprAST*> > () = V; }
#line 1038 "parser.cpp"
    break;

  case 29: // args: expr "," args
#line 153 "parser.yy"
                         { yystack_[0].value.as < std::vector<ExprAST*> > ().insert(yystack_[0].value.as < std::vector<ExprAST*> > ().begin(),yystack_[2].value.as < ExprAST* > ()); yylhs.value.as < std::vector<ExprAST*> > () = yystack_[0].value.as < std::vector<ExprAST*> > (); }
#line 1044 "parser.cpp"
    break;

  case 30: // condexpr: "if" pairs "end"
#line 156 "parser.yy"
                         { yylhs.value.as < IfExprAST* > () = new IfExprAST(yystack_[1].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > ()); }
#line 1050 "parser.cpp"
    break;

  case 31: // pairs: pair
#line 159 "parser.yy"
                         { std::vector<std::pair<ExprAST*, ExprAST*>> P = {yystack_[0].value.as < std::pair<ExprAST*, ExprAST*> > ()}; yylhs.value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > () = P; }
#line 1056 "parser.cpp"
    break;

  case 32: // pairs: pair ";" pairs
#line 160 "parser.yy"
                         { yystack_[0].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > ().begin(),yystack_[2].value.as < std::pair<ExprAST*, ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<ExprAST*, ExprAST*>> > (); }
#line 1062 "parser.cpp"
    break;

  case 33: // pair: boolexpr ":" expr
#line 163 "parser.yy"
                         { std::pair<ExprAST*,ExprAST*> P (yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); yylhs.value.as < std::pair<ExprAST*, ExprAST*> > () = P; }
#line 1068 "parser.cpp"
    break;

  case 34: // boolexpr: boolexpr "and" boolexpr
#line 166 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("and",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1074 "parser.cpp"
    break;

  case 35: // boolexpr: boolexpr "or" boolexpr
#line 167 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("or",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1080 "parser.cpp"
    break;

  case 36: // boolexpr: "not" boolexpr
#line 168 "parser.yy"
                               { yylhs.value.as < ExprAST* > () = new UnaryExprAST("not",yystack_[0].value.as < ExprAST* > ()); }
#line 1086 "parser.cpp"
    break;

  case 37: // boolexpr: literal
#line 169 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1092 "parser.cpp"
    break;

  case 38: // boolexpr: relexpr
#line 170 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = yystack_[0].value.as < ExprAST* > (); }
#line 1098 "parser.cpp"
    break;

  case 39: // literal: "true"
#line 173 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BoolConstAST(1); }
#line 1104 "parser.cpp"
    break;

  case 40: // literal: "false"
#line 174 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BoolConstAST(0); }
#line 1110 "parser.cpp"
    break;

  case 41: // relexpr: expr "<" expr
#line 177 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("<",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1116 "parser.cpp"
    break;

  case 42: // relexpr: expr "==" expr
#line 178 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("==",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1122 "parser.cpp"
    break;

  case 43: // relexpr: expr "<>" expr
#line 179 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("<>",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1128 "parser.cpp"
    break;

  case 44: // relexpr: expr "<=" expr
#line 180 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST("<=",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1134 "parser.cpp"
    break;

  case 45: // relexpr: expr ">" expr
#line 181 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST(">",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1140 "parser.cpp"
    break;

  case 46: // relexpr: expr ">=" expr
#line 182 "parser.yy"
                          { yylhs.value.as < ExprAST* > () = new BinaryExprAST(">=",yystack_[2].value.as < ExprAST* > (),yystack_[0].value.as < ExprAST* > ()); }
#line 1146 "parser.cpp"
    break;

  case 47: // letexpr: "let" bindings "in" expr "end"
#line 185 "parser.yy"
                                 { yylhs.value.as < LetExprAST* > () = new LetExprAST(yystack_[3].value.as < std::vector<std::pair<std::string, ExprAST*>> > (),yystack_[1].value.as < ExprAST* > ()); }
#line 1152 "parser.cpp"
    break;

  case 48: // bindings: binding
#line 188 "parser.yy"
                          { std::vector<std::pair<std::string, ExprAST*>> B = {yystack_[0].value.as < std::pair<std::string, ExprAST*> > ()}; yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = B; }
#line 1158 "parser.cpp"
    break;

  case 49: // bindings: binding "," bindings
#line 189 "parser.yy"
                          { yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().insert(yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > ().begin(),yystack_[2].value.as < std::pair<std::string, ExprAST*> > ()); yylhs.value.as < std::vector<std::pair<std::string, ExprAST*>> > () = yystack_[0].value.as < std::vector<std::pair<std::string, ExprAST*>> > (); }
#line 1164 "parser.cpp"
    break;

  case 50: // binding: "id" "=" expr
#line 192 "parser.yy"
                          { std::pair<std::string, ExprAST*> C (yystack_[2].value.as < std::string > (),yystack_[0].value.as < ExprAST* > ()); yylhs.value.as < std::pair<std::string, ExprAST*> > () = C; }
#line 1170 "parser.cpp"
    break;


#line 1174 "parser.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (yyla.location, YY_MOVE (msg));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yyerror_range[1].location = yystack_[0].location;
        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              else
                goto append;

            append:
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -30;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -2,   -29,   -29,    13,   -30,    -2,   -30,   -30,     4,   -30,
      30,   -30,   -30,   -14,    30,    30,    -5,   -13,    18,   -30,
      58,   -30,   -30,    20,    36,   -14,   -30,     2,   -30,   -30,
      -5,    89,    21,    45,    -1,   -30,   -30,    31,    44,    55,
      30,    30,    30,    30,    30,    30,   -30,    30,   -30,   -30,
     -30,   -30,    30,    30,    30,    30,    30,    30,   -30,    -5,
      30,    -5,    -5,    30,    30,   -13,    74,    49,   -30,    48,
      48,   -30,   -30,   -30,   103,   103,   103,   103,   103,   103,
     103,   -30,   103,   -30,    50,   103,    63,   -30,    30,   -30,
     -30,   -30
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     2,     4,     5,     6,     0,     7,
       0,     1,     3,    10,     0,     0,     0,     0,    21,    23,
       0,    24,    25,    12,     0,    10,    19,     0,    39,    40,
       0,     0,     0,    31,     0,    37,    38,     0,     0,    48,
      26,     0,     0,     0,     0,     0,     8,     0,     9,    11,
      20,    36,     0,     0,     0,     0,     0,     0,    30,     0,
       0,     0,     0,     0,     0,     0,    28,     0,    27,    15,
      14,    16,    17,    18,    13,    44,    41,    42,    43,    46,
      45,    32,    33,    34,    35,    50,     0,    49,     0,    22,
      47,    29
  };

  const signed char
  parser::yypgoto_[] =
  {
     -30,   -30,    70,   -30,   -30,   -30,    75,    60,   -30,   -10,
     -30,     0,   -30,    27,   -30,   -23,   -30,   -30,   -30,    22,
     -30
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     4,     5,     6,     7,     9,    24,    25,    31,
      67,    68,    21,    32,    33,    34,    35,    36,    22,    38,
      39
  };

  const signed char
  parser::yytable_[] =
  {
      20,    14,    60,     8,    26,    27,    15,    51,    41,    42,
      43,    44,    45,    11,    50,    13,    28,    29,    23,    37,
      16,     1,     2,    30,    17,    61,    62,    18,    19,    40,
      66,    69,    70,    71,    72,    73,    14,    74,    83,    84,
      47,    15,    75,    76,    77,    78,    79,    80,    48,    59,
      82,    63,    58,    85,    86,    16,    43,    44,    45,    17,
      65,    89,    18,    19,    41,    42,    43,    44,    45,    41,
      42,    43,    44,    45,    64,    12,    61,    10,    66,    88,
      41,    42,    43,    44,    45,    49,    81,    87,    91,    46,
       0,     0,     0,     0,    90,    41,    42,    43,    44,    45,
       0,     0,     0,    52,    53,    54,    55,    56,    57,    41,
      42,    43,    44,    45
  };

  const signed char
  parser::yycheck_[] =
  {
      10,     6,     3,    32,    14,    15,    11,    30,     6,     7,
       8,     9,    10,     0,    12,    11,    21,    22,    32,    32,
      25,    23,    24,    28,    29,    26,    27,    32,    33,    11,
      40,    41,    42,    43,    44,    45,     6,    47,    61,    62,
      20,    11,    52,    53,    54,    55,    56,    57,    12,     4,
      60,    20,    31,    63,    64,    25,     8,     9,    10,    29,
       5,    12,    32,    33,     6,     7,     8,     9,    10,     6,
       7,     8,     9,    10,    30,     5,    26,     2,    88,     5,
       6,     7,     8,     9,    10,    25,    59,    65,    88,    31,
      -1,    -1,    -1,    -1,    31,     6,     7,     8,     9,    10,
      -1,    -1,    -1,    14,    15,    16,    17,    18,    19,     6,
       7,     8,     9,    10
  };

  const signed char
  parser::yystos_[] =
  {
       0,    23,    24,    37,    38,    39,    40,    41,    32,    42,
      42,     0,    38,    11,     6,    11,    25,    29,    32,    33,
      45,    48,    54,    32,    43,    44,    45,    45,    21,    22,
      28,    45,    49,    50,    51,    52,    53,    32,    55,    56,
      11,     6,     7,     8,     9,    10,    31,    20,    12,    43,
      12,    51,    14,    15,    16,    17,    18,    19,    31,     4,
       3,    26,    27,    20,    30,     5,    45,    46,    47,    45,
      45,    45,    45,    45,    45,    45,    45,    45,    45,    45,
      45,    49,    45,    51,    51,    45,    45,    55,     5,    12,
      31,    47
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    36,    37,    38,    38,    39,    39,    40,    41,    42,
      43,    43,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    45,    46,    46,    47,    47,
      48,    49,    49,    50,    51,    51,    51,    51,    51,    52,
      52,    53,    53,    53,    53,    53,    53,    54,    55,    55,
      56
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     1,     2,     4,     4,
       0,     2,     1,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     4,     1,     1,     1,     0,     1,     1,     3,
       3,     1,     3,     3,     3,     3,     2,     1,     1,     1,
       1,     3,     3,     3,     3,     3,     3,     5,     1,     3,
       3
  };


#if YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "\":\"", "\";\"",
  "\",\"", "\"-\"", "\"+\"", "\"*\"", "\"/\"", "\"%\"", "\"(\"", "\")\"",
  "\"|\"", "\"<=\"", "\"<\"", "\"==\"", "\"<>\"", "\">=\"", "\">\"",
  "\"=\"", "\"true\"", "\"false\"", "\"external\"", "\"function\"",
  "\"if\"", "\"and\"", "\"or\"", "\"not\"", "\"let\"", "\"in\"", "\"end\"",
  "\"id\"", "\"number\"", "UMINUS", "NEGATE", "$accept", "startsymb",
  "deflist", "def", "extdef", "funcdef", "prototype", "params", "param",
  "expr", "arglist", "args", "condexpr", "pairs", "pair", "boolexpr",
  "literal", "relexpr", "letexpr", "bindings", "binding", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    98,    98,   101,   102,   105,   106,   109,   112,   115,
     118,   119,   122,   123,   134,   135,   136,   137,   138,   139,
     140,   141,   142,   143,   144,   145,   148,   149,   152,   153,
     156,   159,   160,   163,   166,   167,   168,   169,   170,   173,
     174,   177,   178,   179,   180,   181,   182,   185,   188,   189,
     192
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1708 "parser.cpp"

#line 194 "parser.yy"


void yy::parser::error (const location_type& l, const std::string& m)
{
  std::cerr << l << ": " << m << '\n';
}
