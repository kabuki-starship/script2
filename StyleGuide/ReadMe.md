# [ASCII C++ Style Guide](./)

## Content Table

1. [Header Files](header_files)
   1. [Self-contained Headers](header_files#self-contained-headers)
   1. [The #define Guard](header_files#the-define-guard)
   1. [Forward Declarations](header_files#forward-declarations)
   1. [Inline Functions](header_files#inline-functions)
   1. [Names and Order of Includes](header_files#names-and-order-of-includes)
1. [Scoping](scoping)
   1. [Namespaces](scoping#namespaces)
   1. [Unnamed Namespaces and Static Variables](scoping#unnamed-namespaces-and-static-variables)
   1. [Nonmember, Static Member, and Global Functions](scoping#nonmember-static-member-and-global-functions)
   1. [Local Variables](scoping#local-variables)
   1. [Static and Global Variables](scoping#static-and-global-variables)
   1. [thread_local Variables](scoping#thread-local-variables)
1. [Classes](classes)
   1. [Doing Work in Constructors](classes#doing-work-in-constructors)
   1. [Implicit Conversions](classes#implicit-conversions)
   1. [Copyable and Movable Types](classes#copyable-and-movable-types)
   1. [Structs vs. Classes](classes#structs-vs-classes)
   1. [Inheritance](classes#inheritance)
   1. [Operator Overloading](classes#operator-overloading)
   1. [Access Control](classes#-access-control)
   1. [Declaration Order](classes#declaration-order)
1. [Functions](functions)
   1. [Output Parameters](functions#output-parameters)
   1. [Write Short Functions](functions#write-short-functions)
   1. [Reference Arguments](functions#reference-arguments)
   1. [Function Overloading](functions#function-overloading)
   1. [Default Arguments](functions#default-arguments)
   1. [Trailing Return Type Syntax](functions#trailing-return-type-syntax)
1. [Other C++ Features](other_cpp_features)
   1. [Rvalue References](other_cpp_features#rvalue-references)
   1. [Friends](other_cpp_features#friends)
   1. [Exceptions](other_cpp_features#exceptions)
   1. [noexcept](other_cpp_features#noexcept)
   1. [Run-Time Type Information (RTTI)](other_cpp_features#run-time-type-information-rtti)
   1. [CastingStreams](other_cpp_features#castingstreams)
   1. [Preincrement and Predecrement](other_cpp_features#preincrement-andpredecrement)
   1. [Use of const](other_cpp_features#use-of-const)
   1. [Use of constexpr](other_cpp_features#use-of-constexpr)
   1. [Integer Types](other_cpp_features#integer-types)
   1. [64-bit Portability](other_cpp_features#64-bit-portability)
   1. [Preprocessor Macros](other_cpp_features#preprocessor-macros)
   1. [0 and nullptr/NULL](other_cpp_features#0-and-nullptr-null)
   1. [sizeof](other_cpp_features#sizeof)
   1. [auto](other_cpp_features#auto)
   1. [Braced Initializer List](other_cpp_features#braced-initializer-list)
   1. [Lambda expressions](other_cpp_features#lambda-expressions)
   1. [Template metaprogramming](other_cpp_features#template-metaprogramming)
   1. [Boost](other_cpp_features#boost)
   1. [std::hash](other_cpp_features#std-hash)
   1. [C++11](other_cpp_features#c-11)
   1. [Nonstandard Extensions](other_cpp_features#nonstandard-extensions)
   1. [Aliases](other_cpp_features#aliases)
1. [Naming](naming)
   1. [General Naming Rules](naming#general-naming-rules)
   1. [File Names](naming#file-names)
   1. [Type Names](naming#type-names)
   1. [Variable Names](naming#variable-names)
   1. [Constant Names](naming#constant-names)
   1. [Function Names](naming#function-names)
   1. [Namespace Names](naming#namespace-names)
   1. [Enumerator Names](naming#enumerator-names)
   1. [Macro Names](naming#macro-names)
   1. [Exceptions to Naming Rules](naming#exceptions-to-naming-rules)
1. [Comments](comments)
   1. [Comment Style](comments#comment-styles)
   1. [File Comments](comments#file-comments)
   1. [Class Comments](comments#class-comments)
   1. [Function Comments](comments#functions-comments)
   1. [Variable Comments](comments#variable-comments)
   1. [Implementation Comments](comments#implementation-comments)
   1. [Punctuation, Spelling and Grammar](comments#punctuation-spelling-and-grammar)
   1. [TODO Comments](comments#todo-comments)
   1. [Deprecation Comments](comments#depreciation-comments)
1. [Formatting](formatting)
   1. [Line Length](formatting#line-arguments)
   1. [Non-ASCII Characters](formatting#non-ascii-characters)
   1. [Spaces vs. Tabs](formatting#spaces-vs-tabs)
   1. [Function Declarations and Definitions](formatting#function-declarations-and-definitions)
   1. [Lambda Expressions](formatting#lambda-expressions)
   1. [Function Calls](formatting#function-calls)
   1. [Braced Initializer List Format](formatting#braces-initializer-list-format)
   1. [Conditionals](formatting#conditionals)
   1. [Loops and Switch Statements](formatting#loops-and-switch-statements)
   1. [Pointer and Reference Expressions](formatting#pointer-and-reference-expressions)
   1. [Boolean Expressions](formatting#boolean-expressions)
   1. [Return Values](formatting#return-values)
   1. [Variable and Array Initialization](formatting#variable-and-array-initalization)
   1. [Preprocessor Directives](formatting#preprocessor-directives)
   1. [Class Format](formatting#class-format)
   1. [Constructor Initializer Lists](formatting#constructor-initializer-lists)
   1. [Namespace Formatting](formatting#namespace-formatting)
   1. [Horizontal Whitespace](formatting#horizontal-whitespace)
   1. [Vertical Whitespace](formatting#vertical-whitespace)
1. [Exceptions to the Rules](exceptions_to_the_rules)
   1. [Existing Non-conformant Code](exceptions_to_the_rules#existing-non-conformant-code)
   1. [Windows Code](exceptions_to_the_rules#windows-code)

## Background

The Automaton Standard Code for Information Interchange (ASCII) C++ Style Guide is a combination of the Google C++ Style Guide with the ASCII Data Specification which is a part of  which is a part of the Serial Chinese Room, Interprocess, and Telemetry (SCRIPT) Specification.

C++ is one of the main development languages used by many of Google's open-source projects. As every C++ programmer knows, the language has many powerful features, but this power brings with it complexity, which in turn can make code more bug-prone and harder to read and maintain.

The goal of this guide is to manage this complexity by describing in detail the dos and don'ts of writing C++ code. These rules exist to keep the code base manageable while still allowing coders to use C++ language features productively.

_Style_, also known as readability, is what we call the conventions that govern our C++ code. The term Style is a bit of a misnomer, since these conventions cover far more than just source file formatting.

Most open-source projects developed by Google conform to the requirements in this guide.

Note that this guide is not a C++ tutorial: we assume that the reader is familiar with the language.

The ASCII C++ Style Guide makes heavy use of the ASCII Data Specificaiton. You can find a copy of the the specificaiton at <https://github.com/KabukiStarship/Script2/blob/master/docs/rfc/ascii_data_specification_rfc>.

### Goals of the Style Guide

* Why do we have this document?
  * There are a few core goals that we believe this guide should serve. These are the fundamental **whys** that underlie all of the individual rules. By bringing these ideas to the fore, we hope to ground discussions and make it clearer to our broader community why the rules are in place and why particular decisions have been made. If you understand what goals each rule is serving, it should be clearer to everyone when a rule may be waived (some can be), and what sort of argument or alternative would be necessary to change a rule in the guide.

The goals of the style guide as we currently see them are as follows:

* Style rules should pull their weight
  * The benefit of a style rule must be large enough to justify asking all of our engineers to remember it. The benefit is measured relative to the codebase we would get without the rule, so a rule against a very harmful practice may still have a small benefit if people are unlikely to do it anyway. This principle mostly explains the rules we don’t have, rather than the rules we do: for example, `goto` contravenes many of the following principles, but is already vanishingly rare, so the Style Guide doesn’t discuss it.
* Optimize for the reader, not the writer
  * Our codebase (and most individual components submitted to it) is expected to continue for quite some time. As a result, more time will be spent reading most of our code than writing it. We explicitly choose to optimize for the experience of our average software engineer reading, maintaining, and debugging code in our codebase rather than ease when writing said code. "Leave a trace for the reader" is a particularly common sub-point of this principle: When something surprising or unusual is happening in a snippet of code (for example, transfer of pointer ownership), leaving textual hints for the reader at the point of use is valuable (`std::unique_ptr` demonstrates the ownership transfer unambiguously at the call site).

* Be consistent with existing code
  * Using one style consistently through our codebase lets us focus on other (more important) issues. Consistency also allows for automation: tools that format your code or adjust your `#include`s only work properly when your code is consistent with the expectations of the tooling. In many cases, rules that are attributed to "Be Consistent" boil down to "Just pick one and stop worrying about it"; the potential value of allowing flexibility on these points is outweighed by the cost of having people argue over them.

* Be consistent with the broader C++ community when appropriate
  * Consistency with the way other organizations use C++ has value for the same reasons as consistency within our code base. If a feature in the C++ standard solves a problem, or if some idiom is widely known and accepted, that's an argument for using it. However, sometimes standard features and idioms are flawed, or were just designed without our codebase's needs in mind. In those cases (as described below) it's appropriate to constrain or ban standard features. In some cases we prefer a homegrown or third-party library over a library defined in the C++ Standard, either out of perceived superiority or insufficient value to transition the codebase to the standard interface.

* Avoid surprising or dangerous constructs
  * C++ has features that are more surprising or dangerous than one might think at a glance. Some style guide restrictions are in place to prevent falling into these pitfalls. There is a high bar for style guide waivers on such restrictions, because waiving such rules often directly risks compromising program correctness.

* Avoid constructs that our average C++ programmer would find tricky or hard to maintain
  * C++ has features that may not be generally appropriate because of the complexity they introduce to the code. In widely used code, it may be more acceptable to use trickier language constructs, because any benefits of more complex implementation are multiplied widely by usage, and the cost in understanding the complexity does not need to be paid again when working with new portions of the codebase. When in doubt, waivers to rules of this type can be sought by asking your project leads. This is specifically important for our codebase because code ownership and team membership changes over time: even if everyone that works with some piece of code currently understands it, such understanding is not guaranteed to hold a few years from now.

* Be mindful of our scale
  * With a codebase of 100+ million lines and thousands of engineers, some mistakes and simplifications for one engineer can become costly for many. For instance it's particularly important to avoid polluting the global namespace: name collisions across a codebase of hundreds of millions of lines are difficult to work with and hard to avoid if everyone puts things into the global namespace.

* Concede to optimization when necessary
  * Performance optimizations can sometimes be necessary and appropriate, even when they conflict with the other principles of this document.

The intent of this document is to provide maximal guidance with reasonable restriction. As always, common sense and good taste should prevail. By this we specifically refer to the established conventions of the entire Google C++ community, not just your personal preferences or those of your team. Be skeptical about and reluctant to use clever or unusual constructs: the absence of a prohibition is not the same as a license to proceed. Use your judgment, and if you are unsure, please don't hesitate to ask your project leads to get additional input.

## C++ Version

Currently, code should target C++11, i.e., should not use C++14 or C++17 features. The C++ version targeted by this guide will advance (aggressively) over time.

Code should avoid features that have been removed from the latest language version (currently C++17), as well as the rare cases where code has a different meaning in that latest version. Use of some C++ features is restricted or disallowed. Do not use [non-standard extensions](#Nonstandard_Extensions).

## Overall Takeaway

Use common sense and **BE_CONSISTENT**.

If you are editing code, take a few minutes to look at the code around you and determine its style. If they use spaces around their `if` clauses, you should, too. If their comments have little boxes of stars around them, make your comments have little boxes of stars around them too.

The point of having style guidelines is to have a common vocabulary of coding so people can concentrate on what you are saying, rather than on how you are saying it. We present global style rules here so people know the vocabulary. But local style is also important. If code you add to a file looks drastically different from the existing code around it, the discontinuity throws readers out of their rhythm when they go to read it. Try to avoid this.

OK, enough writing about writing code; the code itself is much more interesting. Have fun!
