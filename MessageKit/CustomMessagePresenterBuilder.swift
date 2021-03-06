//
//  CustomMessagePresenterBuilder.swift
//  MessageKit
//
//  Created by ChenHao on 16/3/16.
//  Copyright © 2016年 HarriesChen. All rights reserved.
//

import Foundation

open class CustomMessagePresenterBuilder<ViewModelBuilderT, InteractionHandlerT>: ItemPresenterBuilderProtocol where
    ViewModelBuilderT: ViewModelBuilderProtocol,
    ViewModelBuilderT.ModelT: CustomMessageModelProtocol,
    ViewModelBuilderT.ViewModelT: CustomMessageViewModelProtocol,
    InteractionHandlerT: BaseMessageInteractionHandlerProtocol,
    InteractionHandlerT.ViewModelT == ViewModelBuilderT.ViewModelT {

    public typealias ModelT = ViewModelBuilderT.ModelT
    public typealias ViewModelT = ViewModelBuilderT.ViewModelT

    public init(
        viewModelBuilder: ViewModelBuilderT,
        interactionHandler: InteractionHandlerT?) {
            self.viewModelBuilder = viewModelBuilder
            self.interactionHandler = interactionHandler
    }

    let viewModelBuilder: ViewModelBuilderT
    let interactionHandler: InteractionHandlerT?
    open lazy var sizingCell: CustomMessageCollectionViewCell = CustomMessageCollectionViewCell.sizingCell()
    open lazy var customCellStyle: CustomMessageCollectionViewCellStyleProtocol = CustomMessageCollectionViewCellDefaultStyle()
    open lazy var baseCellStyle: BaseMessageCollectionViewCellStyleProtocol = BaseMessageCollectionViewCellDefaultSyle()

    open func canHandle(_ messageItem: MessageItemProtocol) -> Bool {
        return messageItem is CustomMessageModelProtocol ? true : false
    }

    open func createPresenter(with messageItem: MessageItemProtocol) -> ItemPresenterProtocol {
        assert(self.canHandle(messageItem))
        return CustomMessagePresenter<ViewModelBuilderT, InteractionHandlerT>(
            messageModel: messageItem as! ModelT,
            viewModelBuilder: self.viewModelBuilder,
            interactionHandler: self.interactionHandler,
            sizingCell: sizingCell,
            baseCellStyle: self.baseCellStyle,
            customCellStyle: self.customCellStyle
        )
    }

    open var presenterType: ItemPresenterProtocol.Type {
        return CustomMessagePresenter<ViewModelBuilderT, InteractionHandlerT>.self
    }
}
