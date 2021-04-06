#pragma once
#ifndef mirai_cpp_defs_messages_file_message_hpp_H_
#define mirai_cpp_defs_messages_file_message_hpp_H_

#include "mirai/defs/message_interface.hpp"
#include "mirai/defs/qq_types.hpp"

namespace Cyan
{
	class FileMessage : public IMessage
	{
	public:
		FileMessage() : id_(), name_(), internalId_(-1), size_(0) {}
		FileMessage(const FileMessage& m) : 
			id_(m.id_), 
			name_(m.name_), 
			internalId_(m.internalId_), 
			size_(m.size_) {}
		FileMessage(FileMessage&& m) noexcept
		{
			std::swap(this->id_, m.id_);
			std::swap(this->name_, m.name_);
			std::swap(this->internalId_, m.internalId_);
			std::swap(this->size_, m.size_);
		}
		virtual const string& GetType() const override
		{
			return type_;
		}
		virtual bool operator==(const IMessage& m) const override
		{
			if (auto m_ptr = dynamic_cast<const FileMessage*>(&m))
			{
				return m_ptr->id_ == this->id_;
			}
			return false;
		}

		virtual bool Set(const json& json) override
		{
			if (json["type"].is_null() || json["type"].get<string>() != this->GetType())
				throw std::runtime_error("给定的json不正确");

			id_ = json["id"].get<string>();
			name_ = json["name"].get<string>();
			internalId_ = json["internalId"].get<int>();
			size_ = json["size"].get<size_t>();
			return true;
		}
		virtual json ToJson() const override
		{
			return
			{
				{ "type", type_ },
				{ "id", id_ },
				{ "name", name_ },
				{ "internalId", internalId_ },
				{ "size", size_  }
			};
		}

		const string& Id() const { return id_; }
		void Id(const string& id) { id_ = id; }

		const string& Name() const { return name_; }
		void Name(const string& name) { name_ = name; }

		int InternalId() const { return internalId_; }
		void InternalId(int id) { internalId_ = id; }

		size_t FileSize() const { return size_; }
		void FileSize(size_t size) { size_ = size; }

	private:
		const string type_ = "File";
		string id_;
		string name_;
		int internalId_;
		size_t size_;
	};

}
#endif
