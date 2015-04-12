/* Fast__meta.h
 *
 * Loads objects in database.
 * This file contains generated code. Do not modify!
 */

#ifndef Fast_META_H
#define Fast_META_H

#include "cortex.h"

#include "Fast__type.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ::cortex */
extern cx_object _o;

/* ::cortex::Fast */
extern cx_void (*Fast_o);

/* ::cortex::Fast::Binary */
extern cx_class Fast_Binary_o;

/* ::cortex::Fast::Binary::construct() */
extern cx_method Fast_Binary_construct_o;

/* ::cortex::Fast::Binary::deref */
extern cx_member Fast_Binary_deref_o;

/* ::cortex::Fast::Binary::fold() */
extern cx_method Fast_Binary_fold_o;

/* ::cortex::Fast::Binary::hasSideEffects() */
extern cx_virtual Fast_Binary_hasSideEffects_o;

/* ::cortex::Fast::Binary::lvalue */
extern cx_member Fast_Binary_lvalue_o;

/* ::cortex::Fast::Binary::operator */
extern cx_member Fast_Binary_operator_o;

/* ::cortex::Fast::Binary::rvalue */
extern cx_member Fast_Binary_rvalue_o;

/* ::cortex::Fast::Binary::setOperator(operatorKind kind) */
extern cx_method Fast_Binary_setOperator_o;

/* ::cortex::Fast::Binary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Binary_toIc_o;

/* ::cortex::Fast::Binding */
extern cx_struct Fast_Binding_o;

/* ::cortex::Fast::Binding::function */
extern cx_member Fast_Binding_function_o;

/* ::cortex::Fast::Binding::impl */
extern cx_member Fast_Binding_impl_o;

/* ::cortex::Fast::Block */
extern cx_class Fast_Block_o;

/* ::cortex::Fast::Block::addStatement(Fast::Node statement) */
extern cx_method Fast_Block_addStatement_o;

/* ::cortex::Fast::Block::declare(string id,type type,bool isParameter,bool isReference) */
extern cx_method Fast_Block_declare_o;

/* ::cortex::Fast::Block::declareReturnVariable(function function) */
extern cx_method Fast_Block_declareReturnVariable_o;

/* ::cortex::Fast::Block::declareTemplate(string id,type type,bool isParameter,bool isReference) */
extern cx_method Fast_Block_declareTemplate_o;

/* ::cortex::Fast::Block::function */
extern cx_member Fast_Block_function_o;

/* ::cortex::Fast::Block::isRoot */
extern cx_member Fast_Block_isRoot_o;

/* ::cortex::Fast::Block::locals */
extern cx_member Fast_Block_locals_o;

/* ::cortex::Fast::Block::lookup(string id) */
extern cx_method Fast_Block_lookup_o;

/* ::cortex::Fast::Block::lookupLocal(string id) */
extern cx_method Fast_Block_lookupLocal_o;

/* ::cortex::Fast::Block::parent */
extern cx_member Fast_Block_parent_o;

/* ::cortex::Fast::Block::resolve(string id) */
extern cx_method Fast_Block_resolve_o;

/* ::cortex::Fast::Block::resolveLocal(string id) */
extern cx_method Fast_Block_resolveLocal_o;

/* ::cortex::Fast::Block::setFunction(function function */
extern cx_method Fast_Block_setFunction_o;

/* ::cortex::Fast::Block::statements */
extern cx_member Fast_Block_statements_o;

/* ::cortex::Fast::Block::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Block_toIc_o;

/* ::cortex::Fast::Block::toIcBody(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Block_toIcBody_o;

/* ::cortex::Fast::Block::while */
extern cx_member Fast_Block_while_o;

/* ::cortex::Fast::Boolean */
extern cx_class Fast_Boolean_o;

/* ::cortex::Fast::Boolean::init() */
extern cx_method Fast_Boolean_init_o;

/* ::cortex::Fast::Boolean::serialize(type dstType,word dst) */
extern cx_method Fast_Boolean_serialize_o;

/* ::cortex::Fast::Boolean::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Boolean_toIc_o;

/* ::cortex::Fast::Boolean::value */
extern cx_member Fast_Boolean_value_o;

/* ::cortex::Fast::Call */
extern cx_class Fast_Call_o;

/* ::cortex::Fast::Call::arguments */
extern cx_member Fast_Call_arguments_o;

/* ::cortex::Fast::Call::construct() */
extern cx_method Fast_Call_construct_o;

/* ::cortex::Fast::Call::functionExpr */
extern cx_member Fast_Call_functionExpr_o;

/* ::cortex::Fast::Call::hasSideEffects() */
extern cx_virtual Fast_Call_hasSideEffects_o;

/* ::cortex::Fast::Call::instanceExpr */
extern cx_member Fast_Call_instanceExpr_o;

/* ::cortex::Fast::Call::instanceIsAny */
extern cx_member Fast_Call_instanceIsAny_o;

/* ::cortex::Fast::Call::overloaded */
extern cx_member Fast_Call_overloaded_o;

/* ::cortex::Fast::Call::parameters */
extern cx_member Fast_Call_parameters_o;

/* ::cortex::Fast::Call::returnsReference */
extern cx_member Fast_Call_returnsReference_o;

/* ::cortex::Fast::Call::returnType */
extern cx_member Fast_Call_returnType_o;

/* ::cortex::Fast::Call::setParameters(function function) */
extern cx_method Fast_Call_setParameters_o;

/* ::cortex::Fast::Call::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Call_toIc_o;

/* ::cortex::Fast::CallBuilder */
extern cx_struct Fast_CallBuilder_o;

/* ::cortex::Fast::CallBuilder::arguments */
extern cx_member Fast_CallBuilder_arguments_o;

/* ::cortex::Fast::CallBuilder::block */
extern cx_member Fast_CallBuilder_block_o;

/* ::cortex::Fast::CallBuilder::build() */
extern cx_method Fast_CallBuilder_build_o;

/* ::cortex::Fast::CallBuilder::buildSignature() */
extern cx_method Fast_CallBuilder_buildSignature_o;

/* ::cortex::Fast::CallBuilder::instance */
extern cx_member Fast_CallBuilder_instance_o;

/* ::cortex::Fast::CallBuilder::name */
extern cx_member Fast_CallBuilder_name_o;

/* ::cortex::Fast::CallBuilder::overloaded */
extern cx_member Fast_CallBuilder_overloaded_o;

/* ::cortex::Fast::CallBuilder::scope */
extern cx_member Fast_CallBuilder_scope_o;

/* ::cortex::Fast::CallBuilder::signature */
extern cx_member Fast_CallBuilder_signature_o;

/* ::cortex::Fast::Cast */
extern cx_class Fast_Cast_o;

/* ::cortex::Fast::Cast::construct() */
extern cx_method Fast_Cast_construct_o;

/* ::cortex::Fast::Cast::lvalue */
extern cx_member Fast_Cast_lvalue_o;

/* ::cortex::Fast::Cast::rvalue */
extern cx_member Fast_Cast_rvalue_o;

/* ::cortex::Fast::Cast::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Cast_toIc_o;

/* ::cortex::Fast::Character */
extern cx_class Fast_Character_o;

/* ::cortex::Fast::Character::init() */
extern cx_method Fast_Character_init_o;

/* ::cortex::Fast::Character::serialize(type dstType,word dst) */
extern cx_method Fast_Character_serialize_o;

/* ::cortex::Fast::Character::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Character_toIc_o;

/* ::cortex::Fast::Character::value */
extern cx_member Fast_Character_value_o;

/* ::cortex::Fast::Comma */
extern cx_class Fast_Comma_o;

/* ::cortex::Fast::Comma::addExpression(Expression expr) */
extern cx_method Fast_Comma_addExpression_o;

/* ::cortex::Fast::Comma::addOrCreate(Expression list,Expression expr) */
extern cx_function Fast_Comma_addOrCreate_o;

/* ::cortex::Fast::Comma::construct() */
extern cx_method Fast_Comma_construct_o;

/* ::cortex::Fast::Comma::expressions */
extern cx_member Fast_Comma_expressions_o;

/* ::cortex::Fast::Comma::hasSideEffects() */
extern cx_virtual Fast_Comma_hasSideEffects_o;

/* ::cortex::Fast::Comma::init() */
extern cx_method Fast_Comma_init_o;

/* ::cortex::Fast::Comma::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Comma_toIc_o;

/* ::cortex::Fast::Comma::toList() */
extern cx_method Fast_Comma_toList_o;

/* ::cortex::Fast::Define */
extern cx_class Fast_Define_o;

/* ::cortex::Fast::Define::construct() */
extern cx_method Fast_Define_construct_o;

/* ::cortex::Fast::Define::object */
extern cx_member Fast_Define_object_o;

/* ::cortex::Fast::Define::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Define_toIc_o;

/* ::cortex::Fast::DelegateCall */
extern cx_class Fast_DelegateCall_o;

/* ::cortex::Fast::DelegateCall::construct() */
extern cx_method Fast_DelegateCall_construct_o;

/* ::cortex::Fast::DelegateCall::expr */
extern cx_member Fast_DelegateCall_expr_o;

/* ::cortex::Fast::derefKind */
extern cx_enum Fast_derefKind_o;

/* ::cortex::Fast::derefKind::ByReference */
extern cx_constant (*Fast_derefKind_ByReference_o);

/* ::cortex::Fast::derefKind::ByValue */
extern cx_constant (*Fast_derefKind_ByValue_o);

/* ::cortex::Fast::DynamicInitializer */
extern cx_class Fast_DynamicInitializer_o;

/* ::cortex::Fast::DynamicInitializer::assignValue */
extern cx_member Fast_DynamicInitializer_assignValue_o;

/* ::cortex::Fast::DynamicInitializer::construct() */
extern cx_method Fast_DynamicInitializer_construct_o;

/* ::cortex::Fast::DynamicInitializer::define() */
extern cx_method Fast_DynamicInitializer_define_o;

/* ::cortex::Fast::DynamicInitializer::frames */
extern cx_member Fast_DynamicInitializer_frames_o;

/* ::cortex::Fast::DynamicInitializer::pop() */
extern cx_method Fast_DynamicInitializer_pop_o;

/* ::cortex::Fast::DynamicInitializer::push() */
extern cx_method Fast_DynamicInitializer_push_o;

/* ::cortex::Fast::DynamicInitializer::value(Expression v) */
extern cx_method Fast_DynamicInitializer_value_o;

/* ::cortex::Fast::DynamicInitializerFrame */
extern cx_struct Fast_DynamicInitializerFrame_o;

/* ::cortex::Fast::DynamicInitializerFrame::expr */
extern cx_member Fast_DynamicInitializerFrame_expr_o;

/* ::cortex::Fast::DynamicInitializerFrame::keyExpr */
extern cx_member Fast_DynamicInitializerFrame_keyExpr_o;

/* ::cortex::Fast::DynamicInitializerFrame::sequenceSize */
extern cx_member Fast_DynamicInitializerFrame_sequenceSize_o;

/* ::cortex::Fast::Element */
extern cx_class Fast_Element_o;

/* ::cortex::Fast::Element::construct() */
extern cx_method Fast_Element_construct_o;

/* ::cortex::Fast::Element::lvalue */
extern cx_member Fast_Element_lvalue_o;

/* ::cortex::Fast::Element::rvalue */
extern cx_member Fast_Element_rvalue_o;

/* ::cortex::Fast::Element::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Element_toIc_o;

/* ::cortex::Fast::Expression */
extern cx_class Fast_Expression_o;

/* ::cortex::Fast::Expression::cast(type type,bool isReference) */
extern cx_method Fast_Expression_cast_o;

/* ::cortex::Fast::Expression::cleanList(list{Expression} list) */
extern cx_function Fast_Expression_cleanList_o;

/* ::cortex::Fast::Expression::deref */
extern cx_member Fast_Expression_deref_o;

/* ::cortex::Fast::Expression::fold() */
extern cx_virtual Fast_Expression_fold_o;

/* ::cortex::Fast::Expression::fromList(list{Expression} list) */
extern cx_function Fast_Expression_fromList_o;

/* ::cortex::Fast::Expression::getType() */
extern cx_method Fast_Expression_getType_o;

/* ::cortex::Fast::Expression::getType_expr(Expression target) */
extern cx_method Fast_Expression_getType_expr_o;

/* ::cortex::Fast::Expression::getType_type(type target) */
extern cx_method Fast_Expression_getType_type_o;

/* ::cortex::Fast::Expression::getValue() */
extern cx_virtual Fast_Expression_getValue_o;

/* ::cortex::Fast::Expression::hasSideEffects() */
extern cx_virtual Fast_Expression_hasSideEffects_o;

/* ::cortex::Fast::Expression::isReference */
extern cx_member Fast_Expression_isReference_o;

/* ::cortex::Fast::Expression::serialize(type dstType,word dst) */
extern cx_virtual Fast_Expression_serialize_o;

/* ::cortex::Fast::Expression::toList() */
extern cx_virtual Fast_Expression_toList_o;

/* ::cortex::Fast::Expression::type */
extern cx_member Fast_Expression_type_o;

/* ::cortex::Fast::FloatingPoint */
extern cx_class Fast_FloatingPoint_o;

/* ::cortex::Fast::FloatingPoint::init() */
extern cx_method Fast_FloatingPoint_init_o;

/* ::cortex::Fast::FloatingPoint::serialize(type dstType,word dst) */
extern cx_method Fast_FloatingPoint_serialize_o;

/* ::cortex::Fast::FloatingPoint::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_FloatingPoint_toIc_o;

/* ::cortex::Fast::FloatingPoint::value */
extern cx_member Fast_FloatingPoint_value_o;

/* ::cortex::Fast::If */
extern cx_class Fast_If_o;

/* ::cortex::Fast::If::condition */
extern cx_member Fast_If_condition_o;

/* ::cortex::Fast::If::construct() */
extern cx_method Fast_If_construct_o;

/* ::cortex::Fast::If::falseBranch */
extern cx_member Fast_If_falseBranch_o;

/* ::cortex::Fast::If::noWarnUnreachable() */
extern cx_method Fast_If_noWarnUnreachable_o;

/* ::cortex::Fast::If::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_If_toIc_o;

/* ::cortex::Fast::If::trueBranch */
extern cx_member Fast_If_trueBranch_o;

/* ::cortex::Fast::If::warnUnreachable */
extern cx_member Fast_If_warnUnreachable_o;

/* ::cortex::Fast::Initializer */
extern cx_class Fast_Initializer_o;

/* ::cortex::Fast::Initializer::construct() */
extern cx_method Fast_Initializer_construct_o;

/* ::cortex::Fast::Initializer::currentType() */
extern cx_method Fast_Initializer_currentType_o;

/* ::cortex::Fast::Initializer::define() */
extern cx_virtual Fast_Initializer_define_o;

/* ::cortex::Fast::Initializer::fp */
extern cx_member Fast_Initializer_fp_o;

/* ::cortex::Fast::Initializer::frames */
extern cx_member Fast_Initializer_frames_o;

/* ::cortex::Fast::Initializer::initFrame() */
extern cx_method Fast_Initializer_initFrame_o;

/* ::cortex::Fast::Initializer::member(string name) */
extern cx_virtual Fast_Initializer_member_o;

/* ::cortex::Fast::Initializer::next() */
extern cx_virtual Fast_Initializer_next_o;

/* ::cortex::Fast::Initializer::pop() */
extern cx_virtual Fast_Initializer_pop_o;

/* ::cortex::Fast::Initializer::popKey() */
extern cx_virtual Fast_Initializer_popKey_o;

/* ::cortex::Fast::Initializer::push() */
extern cx_virtual Fast_Initializer_push_o;

/* ::cortex::Fast::Initializer::pushKey() */
extern cx_virtual Fast_Initializer_pushKey_o;

/* ::cortex::Fast::Initializer::type() */
extern cx_method Fast_Initializer_type_o;

/* ::cortex::Fast::Initializer::value(Expression v) */
extern cx_virtual Fast_Initializer_value_o;

/* ::cortex::Fast::Initializer::valueKey(Expression key) */
extern cx_virtual Fast_Initializer_valueKey_o;

/* ::cortex::Fast::Initializer::variableCount */
extern cx_member Fast_Initializer_variableCount_o;

/* ::cortex::Fast::Initializer::variables */
extern cx_member Fast_Initializer_variables_o;

/* ::cortex::Fast::InitializerExpression */
extern cx_class Fast_InitializerExpression_o;

/* ::cortex::Fast::InitializerExpression::assignValue */
extern cx_member Fast_InitializerExpression_assignValue_o;

/* ::cortex::Fast::InitializerExpression::construct() */
extern cx_method Fast_InitializerExpression_construct_o;

/* ::cortex::Fast::InitializerExpression::define() */
extern cx_method Fast_InitializerExpression_define_o;

/* ::cortex::Fast::InitializerExpression::insert(Expression variable) */
extern cx_method Fast_InitializerExpression_insert_o;

/* ::cortex::Fast::InitializerExpression::member(string name) */
extern cx_method Fast_InitializerExpression_member_o;

/* ::cortex::Fast::InitializerExpression::operations */
extern cx_member Fast_InitializerExpression_operations_o;

/* ::cortex::Fast::InitializerExpression::pop() */
extern cx_method Fast_InitializerExpression_pop_o;

/* ::cortex::Fast::InitializerExpression::push() */
extern cx_method Fast_InitializerExpression_push_o;

/* ::cortex::Fast::InitializerExpression::value(Expression v) */
extern cx_method Fast_InitializerExpression_value_o;

/* ::cortex::Fast::InitializerFrame */
extern cx_struct Fast_InitializerFrame_o;

/* ::cortex::Fast::InitializerFrame::isKey */
extern cx_member Fast_InitializerFrame_isKey_o;

/* ::cortex::Fast::InitializerFrame::location */
extern cx_member Fast_InitializerFrame_location_o;

/* ::cortex::Fast::InitializerFrame::member */
extern cx_member Fast_InitializerFrame_member_o;

/* ::cortex::Fast::InitializerFrame::type */
extern cx_member Fast_InitializerFrame_type_o;

/* ::cortex::Fast::InitializerKind */
extern cx_enum Fast_InitializerKind_o;

/* ::cortex::Fast::InitializerKind::InitDynamic */
extern cx_constant (*Fast_InitializerKind_InitDynamic_o);

/* ::cortex::Fast::InitializerKind::InitExpression */
extern cx_constant (*Fast_InitializerKind_InitExpression_o);

/* ::cortex::Fast::InitializerKind::InitStatic */
extern cx_constant (*Fast_InitializerKind_InitStatic_o);

/* ::cortex::Fast::InitializerVariable */
extern cx_struct Fast_InitializerVariable_o;

/* ::cortex::Fast::InitializerVariable::key */
extern cx_member Fast_InitializerVariable_key_o;

/* ::cortex::Fast::InitializerVariable::object */
extern cx_member Fast_InitializerVariable_object_o;

/* ::cortex::Fast::InitializerVariable::offset */
extern cx_member Fast_InitializerVariable_offset_o;

/* ::cortex::Fast::InitOper */
extern cx_struct Fast_InitOper_o;

/* ::cortex::Fast::InitOper::expr */
extern cx_member Fast_InitOper_expr_o;

/* ::cortex::Fast::InitOper::kind */
extern cx_member Fast_InitOper_kind_o;

/* ::cortex::Fast::InitOper::name */
extern cx_member Fast_InitOper_name_o;

/* ::cortex::Fast::InitOperKind */
extern cx_enum Fast_InitOperKind_o;

/* ::cortex::Fast::InitOperKind::InitDefine */
extern cx_constant (*Fast_InitOperKind_InitDefine_o);

/* ::cortex::Fast::InitOperKind::InitMember */
extern cx_constant (*Fast_InitOperKind_InitMember_o);

/* ::cortex::Fast::InitOperKind::InitPop */
extern cx_constant (*Fast_InitOperKind_InitPop_o);

/* ::cortex::Fast::InitOperKind::InitPush */
extern cx_constant (*Fast_InitOperKind_InitPush_o);

/* ::cortex::Fast::InitOperKind::InitValue */
extern cx_constant (*Fast_InitOperKind_InitValue_o);

/* ::cortex::Fast::Integer */
extern cx_class Fast_Integer_o;

/* ::cortex::Fast::Integer::init() */
extern cx_method Fast_Integer_init_o;

/* ::cortex::Fast::Integer::serialize(type dstType,word dst) */
extern cx_method Fast_Integer_serialize_o;

/* ::cortex::Fast::Integer::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Integer_toIc_o;

/* ::cortex::Fast::Integer::value */
extern cx_member Fast_Integer_value_o;

/* ::cortex::Fast::isOperatorAssignment(operatorKind operator) */
extern cx_function Fast_isOperatorAssignment_o;

/* ::cortex::Fast::Literal */
extern cx_class Fast_Literal_o;

/* ::cortex::Fast::Literal::getValue() */
extern cx_virtual Fast_Literal_getValue_o;

/* ::cortex::Fast::Literal::init() */
extern cx_method Fast_Literal_init_o;

/* ::cortex::Fast::Literal::kind */
extern cx_member Fast_Literal_kind_o;

/* ::cortex::Fast::Local */
extern cx_class Fast_Local_o;

/* ::cortex::Fast::Local::construct() */
extern cx_method Fast_Local_construct_o;

/* ::cortex::Fast::Local::kind */
extern cx_member Fast_Local_kind_o;

/* ::cortex::Fast::Local::name */
extern cx_member Fast_Local_name_o;

/* ::cortex::Fast::Local::reference */
extern cx_member Fast_Local_reference_o;

/* ::cortex::Fast::Local::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Local_toIc_o;

/* ::cortex::Fast::Local::type */
extern cx_member Fast_Local_type_o;

/* ::cortex::Fast::LocalKind */
extern cx_enum Fast_LocalKind_o;

/* ::cortex::Fast::LocalKind::LocalDefault */
extern cx_constant (*Fast_LocalKind_LocalDefault_o);

/* ::cortex::Fast::LocalKind::LocalParameter */
extern cx_constant (*Fast_LocalKind_LocalParameter_o);

/* ::cortex::Fast::LocalKind::LocalReturn */
extern cx_constant (*Fast_LocalKind_LocalReturn_o);

/* ::cortex::Fast::Lvalue */
extern cx_struct Fast_Lvalue_o;

/* ::cortex::Fast::Lvalue::expr */
extern cx_member Fast_Lvalue_expr_o;

/* ::cortex::Fast::Lvalue::isAssignment */
extern cx_member Fast_Lvalue_isAssignment_o;

/* ::cortex::Fast::Member */
extern cx_class Fast_Member_o;

/* ::cortex::Fast::Member::construct() */
extern cx_method Fast_Member_construct_o;

/* ::cortex::Fast::Member::hasSideEffects() */
extern cx_virtual Fast_Member_hasSideEffects_o;

/* ::cortex::Fast::Member::lvalue */
extern cx_member Fast_Member_lvalue_o;

/* ::cortex::Fast::Member::member */
extern cx_member Fast_Member_member_o;

/* ::cortex::Fast::Member::rvalue */
extern cx_member Fast_Member_rvalue_o;

/* ::cortex::Fast::Member::superMember */
extern cx_member Fast_Member_superMember_o;

/* ::cortex::Fast::Member::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Member_toIc_o;

/* ::cortex::Fast::New */
extern cx_class Fast_New_o;

/* ::cortex::Fast::New::attributes */
extern cx_member Fast_New_attributes_o;

/* ::cortex::Fast::New::construct() */
extern cx_method Fast_New_construct_o;

/* ::cortex::Fast::New::hasSideEffects() */
extern cx_virtual Fast_New_hasSideEffects_o;

/* ::cortex::Fast::New::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_New_toIc_o;

/* ::cortex::Fast::New::type */
extern cx_member Fast_New_type_o;

/* ::cortex::Fast::Node */
extern cx_class Fast_Node_o;

/* ::cortex::Fast::Node::column */
extern cx_member Fast_Node_column_o;

/* ::cortex::Fast::Node::init() */
extern cx_method Fast_Node_init_o;

/* ::cortex::Fast::Node::kind */
extern cx_member Fast_Node_kind_o;

/* ::cortex::Fast::Node::line */
extern cx_member Fast_Node_line_o;

/* ::cortex::Fast::Node::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Node_toIc_o;

/* ::cortex::Fast::nodeKind */
extern cx_enum Fast_nodeKind_o;

/* ::cortex::Fast::nodeKind::BinaryExpr */
extern cx_constant (*Fast_nodeKind_BinaryExpr_o);

/* ::cortex::Fast::nodeKind::CallExpr */
extern cx_constant (*Fast_nodeKind_CallExpr_o);

/* ::cortex::Fast::nodeKind::CastExpr */
extern cx_constant (*Fast_nodeKind_CastExpr_o);

/* ::cortex::Fast::nodeKind::CommaExpr */
extern cx_constant (*Fast_nodeKind_CommaExpr_o);

/* ::cortex::Fast::nodeKind::DeclarationExpr */
extern cx_constant (*Fast_nodeKind_DeclarationExpr_o);

/* ::cortex::Fast::nodeKind::DeclareExpr */
extern cx_constant (*Fast_nodeKind_DeclareExpr_o);

/* ::cortex::Fast::nodeKind::DefineExpr */
extern cx_constant (*Fast_nodeKind_DefineExpr_o);

/* ::cortex::Fast::nodeKind::IfExpr */
extern cx_constant (*Fast_nodeKind_IfExpr_o);

/* ::cortex::Fast::nodeKind::InitializerExpr */
extern cx_constant (*Fast_nodeKind_InitializerExpr_o);

/* ::cortex::Fast::nodeKind::LiteralExpr */
extern cx_constant (*Fast_nodeKind_LiteralExpr_o);

/* ::cortex::Fast::nodeKind::MethodExpr */
extern cx_constant (*Fast_nodeKind_MethodExpr_o);

/* ::cortex::Fast::nodeKind::NewExpr */
extern cx_constant (*Fast_nodeKind_NewExpr_o);

/* ::cortex::Fast::nodeKind::PostfixExpr */
extern cx_constant (*Fast_nodeKind_PostfixExpr_o);

/* ::cortex::Fast::nodeKind::StorageExpr */
extern cx_constant (*Fast_nodeKind_StorageExpr_o);

/* ::cortex::Fast::nodeKind::TernaryExpr */
extern cx_constant (*Fast_nodeKind_TernaryExpr_o);

/* ::cortex::Fast::nodeKind::UnaryExpr */
extern cx_constant (*Fast_nodeKind_UnaryExpr_o);

/* ::cortex::Fast::nodeKind::UpdateExpr */
extern cx_constant (*Fast_nodeKind_UpdateExpr_o);

/* ::cortex::Fast::nodeKind::WaitExpr */
extern cx_constant (*Fast_nodeKind_WaitExpr_o);

/* ::cortex::Fast::nodeKind::WhileExpr */
extern cx_constant (*Fast_nodeKind_WhileExpr_o);

/* ::cortex::Fast::Null */
extern cx_class Fast_Null_o;

/* ::cortex::Fast::Null::init() */
extern cx_method Fast_Null_init_o;

/* ::cortex::Fast::Null::serialize(type dstType,word dst) */
extern cx_method Fast_Null_serialize_o;

/* ::cortex::Fast::Null::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Null_toIc_o;

/* ::cortex::Fast::Object */
extern cx_class Fast_Object_o;

/* ::cortex::Fast::Object::construct() */
extern cx_method Fast_Object_construct_o;

/* ::cortex::Fast::Object::getValue() */
extern cx_method Fast_Object_getValue_o;

/* ::cortex::Fast::Object::serialize(type dstType,word dst) */
extern cx_method Fast_Object_serialize_o;

/* ::cortex::Fast::Object::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Object_toIc_o;

/* ::cortex::Fast::Object::value */
extern cx_member Fast_Object_value_o;

/* ::cortex::Fast::Parser */
extern cx_class Fast_Parser_o;

/* ::cortex::Fast::Parser::abort */
extern cx_member Fast_Parser_abort_o;

/* ::cortex::Fast::Parser::addStatement(Fast::Node statement) */
extern cx_method Fast_Parser_addStatement_o;

/* ::cortex::Fast::Parser::argumentToString(type type,string id,bool reference) */
extern cx_method Fast_Parser_argumentToString_o;

/* ::cortex::Fast::Parser::binaryExpr(Fast::Expression lvalues,Fast::Expression rvalues,operatorKind operator) */
extern cx_method Fast_Parser_binaryExpr_o;

/* ::cortex::Fast::Parser::bind(Fast::Storage function,Fast::Block block) */
extern cx_method Fast_Parser_bind_o;

/* ::cortex::Fast::Parser::bindings */
extern cx_member Fast_Parser_bindings_o;

/* ::cortex::Fast::Parser::bindOneliner(Fast::Storage function,Fast::Block block,Fast::Expression expr) */
extern cx_method Fast_Parser_bindOneliner_o;

/* ::cortex::Fast::Parser::block */
extern cx_member Fast_Parser_block_o;

/* ::cortex::Fast::Parser::blockCount */
extern cx_member Fast_Parser_blockCount_o;

/* ::cortex::Fast::Parser::blockPop() */
extern cx_method Fast_Parser_blockPop_o;

/* ::cortex::Fast::Parser::blockPreset */
extern cx_member Fast_Parser_blockPreset_o;

/* ::cortex::Fast::Parser::blockPush(bool presetBlock) */
extern cx_method Fast_Parser_blockPush_o;

/* ::cortex::Fast::Parser::callExpr(Fast::Expression function,Fast::Expression arguments) */
extern cx_method Fast_Parser_callExpr_o;

/* ::cortex::Fast::Parser::castExpr(type lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_castExpr_o;

/* ::cortex::Fast::Parser::collect(object o) */
extern cx_method Fast_Parser_collect_o;

/* ::cortex::Fast::Parser::collected */
extern cx_member Fast_Parser_collected_o;

/* ::cortex::Fast::Parser::collectHeap(word addr) */
extern cx_method Fast_Parser_collectHeap_o;

/* ::cortex::Fast::Parser::column */
extern cx_member Fast_Parser_column_o;

/* ::cortex::Fast::Parser::complexType */
extern cx_member Fast_Parser_complexType_o;

/* ::cortex::Fast::Parser::complexTypeSp */
extern cx_member Fast_Parser_complexTypeSp_o;

/* ::cortex::Fast::Parser::construct() */
extern cx_method Fast_Parser_construct_o;

/* ::cortex::Fast::Parser::declaration(type type,string id,bool isReference) */
extern cx_method Fast_Parser_declaration_o;

/* ::cortex::Fast::Parser::declareFunction(type returnType,string id,type kind,bool returnsReference) */
extern cx_method Fast_Parser_declareFunction_o;

/* ::cortex::Fast::Parser::declareFunctionParams(Storage function) */
extern cx_method Fast_Parser_declareFunctionParams_o;

/* ::cortex::Fast::Parser::define() */
extern cx_method Fast_Parser_define_o;

/* ::cortex::Fast::Parser::defineScope() */
extern cx_method Fast_Parser_defineScope_o;

/* ::cortex::Fast::Parser::defineVariable(Storage object) */
extern cx_method Fast_Parser_defineVariable_o;

/* ::cortex::Fast::Parser::destruct() */
extern cx_method Fast_Parser_destruct_o;

/* ::cortex::Fast::Parser::elementExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_elementExpr_o;

/* ::cortex::Fast::Parser::errLine */
extern cx_member Fast_Parser_errLine_o;

/* ::cortex::Fast::Parser::errors */
extern cx_member Fast_Parser_errors_o;

/* ::cortex::Fast::Parser::errSet */
extern cx_member Fast_Parser_errSet_o;

/* ::cortex::Fast::Parser::filename */
extern cx_member Fast_Parser_filename_o;

/* ::cortex::Fast::Parser::finalize(alias{"cx_icProgram"} program) */
extern cx_method Fast_Parser_finalize_o;

/* ::cortex::Fast::Parser::foreach(string loopId,Fast::Expression collection) */
extern cx_method Fast_Parser_foreach_o;

/* ::cortex::Fast::Parser::getComplexType() */
extern cx_method Fast_Parser_getComplexType_o;

/* ::cortex::Fast::Parser::getLvalue(bool assignment) */
extern cx_method Fast_Parser_getLvalue_o;

/* ::cortex::Fast::Parser::getLvalueType(bool assignment) */
extern cx_method Fast_Parser_getLvalueType_o;

/* ::cortex::Fast::Parser::heapCollected */
extern cx_member Fast_Parser_heapCollected_o;

/* ::cortex::Fast::Parser::ifStatement(Fast::Expression condition,Fast::Block trueBranch,Fast::If falseBranch) */
extern cx_method Fast_Parser_ifStatement_o;

/* ::cortex::Fast::Parser::initAnonymousId */
extern cx_member Fast_Parser_initAnonymousId_o;

/* ::cortex::Fast::Parser::initDeclareStaged(Fast::Expression expr) */
extern cx_method Fast_Parser_initDeclareStaged_o;

/* ::cortex::Fast::Parser::initDynamic */
extern cx_member Fast_Parser_initDynamic_o;

/* ::cortex::Fast::Parser::initializerCount */
extern cx_member Fast_Parser_initializerCount_o;

/* ::cortex::Fast::Parser::initializers */
extern cx_member Fast_Parser_initializers_o;

/* ::cortex::Fast::Parser::initKeyValuePop() */
extern cx_method Fast_Parser_initKeyValuePop_o;

/* ::cortex::Fast::Parser::initKeyValuePush() */
extern cx_method Fast_Parser_initKeyValuePush_o;

/* ::cortex::Fast::Parser::initKeyValueSet(Fast::Expression expr) */
extern cx_method Fast_Parser_initKeyValueSet_o;

/* ::cortex::Fast::Parser::initMember(string member) */
extern cx_method Fast_Parser_initMember_o;

/* ::cortex::Fast::Parser::initPop() */
extern cx_method Fast_Parser_initPop_o;

/* ::cortex::Fast::Parser::initPush() */
extern cx_method Fast_Parser_initPush_o;

/* ::cortex::Fast::Parser::initPushExpression() */
extern cx_method Fast_Parser_initPushExpression_o;

/* ::cortex::Fast::Parser::initPushIdentifier(Expression type) */
extern cx_method Fast_Parser_initPushIdentifier_o;

/* ::cortex::Fast::Parser::initPushStatic() */
extern cx_method Fast_Parser_initPushStatic_o;

/* ::cortex::Fast::Parser::initStage(string id,bool found) */
extern cx_method Fast_Parser_initStage_o;

/* ::cortex::Fast::Parser::initValue(Expression expr) */
extern cx_method Fast_Parser_initValue_o;

/* ::cortex::Fast::Parser::isAbortSet() */
extern cx_method Fast_Parser_isAbortSet_o;

/* ::cortex::Fast::Parser::isErrSet() */
extern cx_method Fast_Parser_isErrSet_o;

/* ::cortex::Fast::Parser::isLocal */
extern cx_member Fast_Parser_isLocal_o;

/* ::cortex::Fast::Parser::lastFailedResolve */
extern cx_member Fast_Parser_lastFailedResolve_o;

/* ::cortex::Fast::Parser::line */
extern cx_member Fast_Parser_line_o;

/* ::cortex::Fast::Parser::lookup(string id,object source) */
extern cx_method Fast_Parser_lookup_o;

/* ::cortex::Fast::Parser::lvalue */
extern cx_member Fast_Parser_lvalue_o;

/* ::cortex::Fast::Parser::lvalueSp */
extern cx_member Fast_Parser_lvalueSp_o;

/* ::cortex::Fast::Parser::memberExpr(Fast::Expression lvalue,Fast::Expression rvalue) */
extern cx_method Fast_Parser_memberExpr_o;

/* ::cortex::Fast::Parser::observerDeclaration(string id,Fast::Expression object,eventMask mask,Fast::Object dispatcher) */
extern cx_method Fast_Parser_observerDeclaration_o;

/* ::cortex::Fast::Parser::observerPush() */
extern cx_method Fast_Parser_observerPush_o;

/* ::cortex::Fast::Parser::parse() */
extern cx_method Fast_Parser_parse_o;

/* ::cortex::Fast::Parser::parseExpression(string expr,Fast::Block block,object scope,uint32 line,uint32 column) */
extern cx_method Fast_Parser_parseExpression_o;

/* ::cortex::Fast::Parser::parseLine(string expr,object scope,alias{"cx_value*"} value) */
extern cx_function Fast_Parser_parseLine_o;

/* ::cortex::Fast::Parser::parseSingleExpr */
extern cx_member Fast_Parser_parseSingleExpr_o;

/* ::cortex::Fast::Parser::pass */
extern cx_member Fast_Parser_pass_o;

/* ::cortex::Fast::Parser::popComplexType() */
extern cx_method Fast_Parser_popComplexType_o;

/* ::cortex::Fast::Parser::popLvalue() */
extern cx_method Fast_Parser_popLvalue_o;

/* ::cortex::Fast::Parser::popScope(object previous) */
extern cx_method Fast_Parser_popScope_o;

/* ::cortex::Fast::Parser::postfixExpr(Fast::Expression lvalue,operatorKind operator) */
extern cx_method Fast_Parser_postfixExpr_o;

/* ::cortex::Fast::Parser::preprocessed */
extern cx_member Fast_Parser_preprocessed_o;

/* ::cortex::Fast::Parser::pushComplexType(Fast::Expression lvalue) */
extern cx_method Fast_Parser_pushComplexType_o;

/* ::cortex::Fast::Parser::pushLvalue(Fast::Expression lvalue,bool isAssignment) */
extern cx_method Fast_Parser_pushLvalue_o;

/* ::cortex::Fast::Parser::pushPackage(string name) */
extern cx_method Fast_Parser_pushPackage_o;

/* ::cortex::Fast::Parser::pushReturnAsLvalue(function function) */
extern cx_method Fast_Parser_pushReturnAsLvalue_o;

/* ::cortex::Fast::Parser::pushScope() */
extern cx_method Fast_Parser_pushScope_o;

/* ::cortex::Fast::Parser::repl */
extern cx_member Fast_Parser_repl_o;

/* ::cortex::Fast::Parser::reset() */
extern cx_method Fast_Parser_reset_o;

/* ::cortex::Fast::Parser::scope */
extern cx_member Fast_Parser_scope_o;

/* ::cortex::Fast::Parser::singleExpr */
extern cx_member Fast_Parser_singleExpr_o;

/* ::cortex::Fast::Parser::source */
extern cx_member Fast_Parser_source_o;

/* ::cortex::Fast::Parser::staged */
extern cx_member Fast_Parser_staged_o;

/* ::cortex::Fast::Parser::stagedCount */
extern cx_member Fast_Parser_stagedCount_o;

/* ::cortex::Fast::Parser::stagedId */
extern cx_struct Fast_Parser_stagedId_o;

/* ::cortex::Fast::Parser::stagedId::column */
extern cx_member Fast_Parser_stagedId_column_o;

/* ::cortex::Fast::Parser::stagedId::found */
extern cx_member Fast_Parser_stagedId_found_o;

/* ::cortex::Fast::Parser::stagedId::line */
extern cx_member Fast_Parser_stagedId_line_o;

/* ::cortex::Fast::Parser::stagedId::name */
extern cx_member Fast_Parser_stagedId_name_o;

/* ::cortex::Fast::Parser::stagingAllowed */
extern cx_member Fast_Parser_stagingAllowed_o;

/* ::cortex::Fast::Parser::ternaryExpr(Fast::Expression cond,Fast::Expression iftrue,Fast::Expression iffalse) */
extern cx_method Fast_Parser_ternaryExpr_o;

/* ::cortex::Fast::Parser::token */
extern cx_member Fast_Parser_token_o;

/* ::cortex::Fast::Parser::unaryExpr(Fast::Expression lvalue,operatorKind operator) */
extern cx_method Fast_Parser_unaryExpr_o;

/* ::cortex::Fast::Parser::updateStatement(Fast::Expression expr,Fast::Block block) */
extern cx_method Fast_Parser_updateStatement_o;

/* ::cortex::Fast::Parser::variableCount */
extern cx_member Fast_Parser_variableCount_o;

/* ::cortex::Fast::Parser::variablePushed */
extern cx_member Fast_Parser_variablePushed_o;

/* ::cortex::Fast::Parser::variables */
extern cx_member Fast_Parser_variables_o;

/* ::cortex::Fast::Parser::variablesInitialized */
extern cx_member Fast_Parser_variablesInitialized_o;

/* ::cortex::Fast::Parser::waitExpr(list{Fast::Expression} exprList,Fast::Expression timeout) */
extern cx_method Fast_Parser_waitExpr_o;

/* ::cortex::Fast::Parser::warnings */
extern cx_member Fast_Parser_warnings_o;

/* ::cortex::Fast::Parser::whileStatement(Fast::Expression condition,Fast::Block trueBranch,bool isUntil) */
extern cx_method Fast_Parser_whileStatement_o;

/* ::cortex::Fast::ParserDeclaration */
extern cx_struct Fast_ParserDeclaration_o;

/* ::cortex::Fast::ParserDeclaration::name */
extern cx_member Fast_ParserDeclaration_name_o;

/* ::cortex::Fast::ParserDeclaration::storage */
extern cx_member Fast_ParserDeclaration_storage_o;

/* ::cortex::Fast::ParserDeclarationSeq */
extern cx_sequence Fast_ParserDeclarationSeq_o;

/* ::cortex::Fast::ParserNew */
extern cx_struct Fast_ParserNew_o;

/* ::cortex::Fast::ParserNew::attr */
extern cx_member Fast_ParserNew_attr_o;

/* ::cortex::Fast::ParserNew::kind */
extern cx_member Fast_ParserNew_kind_o;

/* ::cortex::Fast::ParserNew::name */
extern cx_member Fast_ParserNew_name_o;

/* ::cortex::Fast::ParserNew::parent */
extern cx_member Fast_ParserNew_parent_o;

/* ::cortex::Fast::PostFix */
extern cx_class Fast_PostFix_o;

/* ::cortex::Fast::PostFix::construct() */
extern cx_method Fast_PostFix_construct_o;

/* ::cortex::Fast::PostFix::lvalue */
extern cx_member Fast_PostFix_lvalue_o;

/* ::cortex::Fast::PostFix::operator */
extern cx_member Fast_PostFix_operator_o;

/* ::cortex::Fast::PostFix::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_PostFix_toIc_o;

/* ::cortex::Fast::report(string kind,string filename,uint32 line,uint32 column,string error,string token) */
extern cx_function Fast_report_o;

/* ::cortex::Fast::reportError(string filename,uint32 line,uint32 column,string error,string token) */
extern cx_function Fast_reportError_o;

/* ::cortex::Fast::reportWarning(string filename,uint32 line,uint32 column,string error,string token) */
extern cx_function Fast_reportWarning_o;

/* ::cortex::Fast::SignedInteger */
extern cx_class Fast_SignedInteger_o;

/* ::cortex::Fast::SignedInteger::init() */
extern cx_method Fast_SignedInteger_init_o;

/* ::cortex::Fast::SignedInteger::serialize(type dstType,word dst) */
extern cx_method Fast_SignedInteger_serialize_o;

/* ::cortex::Fast::SignedInteger::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_SignedInteger_toIc_o;

/* ::cortex::Fast::SignedInteger::value */
extern cx_member Fast_SignedInteger_value_o;

/* ::cortex::Fast::StaticCall */
extern cx_class Fast_StaticCall_o;

/* ::cortex::Fast::StaticCall::construct() */
extern cx_method Fast_StaticCall_construct_o;

/* ::cortex::Fast::StaticCall::function */
extern cx_member Fast_StaticCall_function_o;

/* ::cortex::Fast::StaticInitializer */
extern cx_class Fast_StaticInitializer_o;

/* ::cortex::Fast::StaticInitializer::construct() */
extern cx_method Fast_StaticInitializer_construct_o;

/* ::cortex::Fast::StaticInitializer::define() */
extern cx_method Fast_StaticInitializer_define_o;

/* ::cortex::Fast::StaticInitializer::frames */
extern cx_member Fast_StaticInitializer_frames_o;

/* ::cortex::Fast::StaticInitializer::push() */
extern cx_method Fast_StaticInitializer_push_o;

/* ::cortex::Fast::StaticInitializer::value(Expression v) */
extern cx_method Fast_StaticInitializer_value_o;

/* ::cortex::Fast::StaticInitializerFrame */
extern cx_struct Fast_StaticInitializerFrame_o;

/* ::cortex::Fast::StaticInitializerFrame::keyPtr */
extern cx_member Fast_StaticInitializerFrame_keyPtr_o;

/* ::cortex::Fast::StaticInitializerFrame::ptr */
extern cx_member Fast_StaticInitializerFrame_ptr_o;

/* ::cortex::Fast::Storage */
extern cx_class Fast_Storage_o;

/* ::cortex::Fast::Storage::construct() */
extern cx_method Fast_Storage_construct_o;

/* ::cortex::Fast::Storage::kind */
extern cx_member Fast_Storage_kind_o;

/* ::cortex::Fast::storageKind */
extern cx_enum Fast_storageKind_o;

/* ::cortex::Fast::storageKind::ElementStorage */
extern cx_constant (*Fast_storageKind_ElementStorage_o);

/* ::cortex::Fast::storageKind::LocalStorage */
extern cx_constant (*Fast_storageKind_LocalStorage_o);

/* ::cortex::Fast::storageKind::MemberStorage */
extern cx_constant (*Fast_storageKind_MemberStorage_o);

/* ::cortex::Fast::storageKind::ObjectStorage */
extern cx_constant (*Fast_storageKind_ObjectStorage_o);

/* ::cortex::Fast::storageKind::TemplateStorage */
extern cx_constant (*Fast_storageKind_TemplateStorage_o);

/* ::cortex::Fast::String */
extern cx_class Fast_String_o;

/* ::cortex::Fast::String::block */
extern cx_member Fast_String_block_o;

/* ::cortex::Fast::String::construct() */
extern cx_method Fast_String_construct_o;

/* ::cortex::Fast::String::elements */
extern cx_member Fast_String_elements_o;

/* ::cortex::Fast::String::getValue() */
extern cx_method Fast_String_getValue_o;

/* ::cortex::Fast::String::init() */
extern cx_method Fast_String_init_o;

/* ::cortex::Fast::String::scope */
extern cx_member Fast_String_scope_o;

/* ::cortex::Fast::String::serialize(type dstType,word dst) */
extern cx_method Fast_String_serialize_o;

/* ::cortex::Fast::String::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_String_toIc_o;

/* ::cortex::Fast::String::value */
extern cx_member Fast_String_value_o;

/* ::cortex::Fast::Template */
extern cx_class Fast_Template_o;

/* ::cortex::Fast::Template::construct() */
extern cx_method Fast_Template_construct_o;

/* ::cortex::Fast::Ternary */
extern cx_class Fast_Ternary_o;

/* ::cortex::Fast::Ternary::condition */
extern cx_member Fast_Ternary_condition_o;

/* ::cortex::Fast::Ternary::construct() */
extern cx_method Fast_Ternary_construct_o;

/* ::cortex::Fast::Ternary::hasSideEffects() */
extern cx_virtual Fast_Ternary_hasSideEffects_o;

/* ::cortex::Fast::Ternary::ifFalse */
extern cx_member Fast_Ternary_ifFalse_o;

/* ::cortex::Fast::Ternary::ifFalseExpr */
extern cx_member Fast_Ternary_ifFalseExpr_o;

/* ::cortex::Fast::Ternary::ifstmt */
extern cx_member Fast_Ternary_ifstmt_o;

/* ::cortex::Fast::Ternary::ifTrue */
extern cx_member Fast_Ternary_ifTrue_o;

/* ::cortex::Fast::Ternary::ifTrueExpr */
extern cx_member Fast_Ternary_ifTrueExpr_o;

/* ::cortex::Fast::Ternary::result */
extern cx_member Fast_Ternary_result_o;

/* ::cortex::Fast::Ternary::setOperator(operatorKind kind) */
extern cx_method Fast_Ternary_setOperator_o;

/* ::cortex::Fast::Ternary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Ternary_toIc_o;

/* ::cortex::Fast::Unary */
extern cx_class Fast_Unary_o;

/* ::cortex::Fast::Unary::construct() */
extern cx_method Fast_Unary_construct_o;

/* ::cortex::Fast::Unary::hasSideEffects() */
extern cx_virtual Fast_Unary_hasSideEffects_o;

/* ::cortex::Fast::Unary::lvalue */
extern cx_member Fast_Unary_lvalue_o;

/* ::cortex::Fast::Unary::operator */
extern cx_member Fast_Unary_operator_o;

/* ::cortex::Fast::Unary::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Unary_toIc_o;

/* ::cortex::Fast::Update */
extern cx_class Fast_Update_o;

/* ::cortex::Fast::Update::block */
extern cx_member Fast_Update_block_o;

/* ::cortex::Fast::Update::construct() */
extern cx_method Fast_Update_construct_o;

/* ::cortex::Fast::Update::exprList */
extern cx_member Fast_Update_exprList_o;

/* ::cortex::Fast::Update::from */
extern cx_member Fast_Update_from_o;

/* ::cortex::Fast::Update::kind */
extern cx_member Fast_Update_kind_o;

/* ::cortex::Fast::Update::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Update_toIc_o;

/* ::cortex::Fast::UpdateKind */
extern cx_enum Fast_UpdateKind_o;

/* ::cortex::Fast::UpdateKind::UpdateBegin */
extern cx_constant (*Fast_UpdateKind_UpdateBegin_o);

/* ::cortex::Fast::UpdateKind::UpdateDefault */
extern cx_constant (*Fast_UpdateKind_UpdateDefault_o);

/* ::cortex::Fast::UpdateKind::UpdateEnd */
extern cx_constant (*Fast_UpdateKind_UpdateEnd_o);

/* ::cortex::Fast::valueKind */
extern cx_enum Fast_valueKind_o;

/* ::cortex::Fast::valueKind::Bool */
extern cx_constant (*Fast_valueKind_Bool_o);

/* ::cortex::Fast::valueKind::Char */
extern cx_constant (*Fast_valueKind_Char_o);

/* ::cortex::Fast::valueKind::Enum */
extern cx_constant (*Fast_valueKind_Enum_o);

/* ::cortex::Fast::valueKind::Float */
extern cx_constant (*Fast_valueKind_Float_o);

/* ::cortex::Fast::valueKind::Int */
extern cx_constant (*Fast_valueKind_Int_o);

/* ::cortex::Fast::valueKind::Nothing */
extern cx_constant (*Fast_valueKind_Nothing_o);

/* ::cortex::Fast::valueKind::Ref */
extern cx_constant (*Fast_valueKind_Ref_o);

/* ::cortex::Fast::valueKind::SignedInt */
extern cx_constant (*Fast_valueKind_SignedInt_o);

/* ::cortex::Fast::valueKind::Text */
extern cx_constant (*Fast_valueKind_Text_o);

/* ::cortex::Fast::valueKindFromType(lang::type type) */
extern cx_function Fast_valueKindFromType_o;

/* ::cortex::Fast::Wait */
extern cx_class Fast_Wait_o;

/* ::cortex::Fast::Wait::construct() */
extern cx_method Fast_Wait_construct_o;

/* ::cortex::Fast::Wait::exprList */
extern cx_member Fast_Wait_exprList_o;

/* ::cortex::Fast::Wait::timeout */
extern cx_member Fast_Wait_timeout_o;

/* ::cortex::Fast::Wait::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_Wait_toIc_o;

/* ::cortex::Fast::While */
extern cx_class Fast_While_o;

/* ::cortex::Fast::While::condition */
extern cx_member Fast_While_condition_o;

/* ::cortex::Fast::While::construct() */
extern cx_method Fast_While_construct_o;

/* ::cortex::Fast::While::isUntil */
extern cx_member Fast_While_isUntil_o;

/* ::cortex::Fast::While::toIc(alias{"cx_icProgram"} program,alias{"cx_icStorage"} storage,bool stored) */
extern cx_virtual Fast_While_toIc_o;

/* ::cortex::Fast::While::trueBranch */
extern cx_member Fast_While_trueBranch_o;

int Fast_load(void);
#ifdef __cplusplus
}
#endif
#endif

